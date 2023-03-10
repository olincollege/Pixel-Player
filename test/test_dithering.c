#include "../src/dithering.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>


const double TWO_FIVE_FIVE = 255.0;
// function to assign a value to each spot in an array
void assign(double** arr, int height, int width, double val) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            arr[i][j] = val;
        }
    }
}

// Check that passing a positive number to get_new_value returns a positive number
Test(test_new_value, positive_num) {
    
    cr_assert(eq(get_new_value(TWO_FIVE_FIVE), 1.0));
}
// Check that passing zero to get_new_value returns zero
Test(test_new_value, zero) {
    cr_assert(eq(get_new_value(0.0), 0.0));
}
// check that passing a negative number to get_new_value returns a negative number
Test(test_new_value, negative_num) {
    cr_assert(eq(get_new_value(TWO_FIVE_FIVE * -1.0), -1.0));
}

static double** make_array(int height, int width) {
    double** arr = (double**) malloc (height * sizeof(double*));

    for(int i = 0; i < height; i++) {
        arr[i] = (double*) malloc (width * sizeof(double));
    }
    return arr;
}

static void test_array(double** arr_calc, double** arr_expect, int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cr_assert(eq(arr_calc[i][j], arr_expect[i][j]));
        }
    }
}

// check that dithering an array of 0s does not alter that array
Test(test_dither, array_zeros) {
    const int five = 5;
    double** arr = make_array(five, five);

    assign(arr, five, five, 0.0);

    double** expected_arr = make_array(five, five);
    assign(expected_arr, five, five, 0.0);

    dither(arr, five, five);

    test_array(arr, expected_arr, five, five);

    free(arr);
    free(expected_arr);

}
// Check that printing an array of zeros prints a bunch of $
Test(test_print, array_full, .init = cr_redirect_stdout) {
    int height = 1;
    int width = 1;
    double** arr = (double**) malloc (height * sizeof(double*));
    for(int i = 0; i < height; i++) {
        arr[i] = (double*) malloc (width * sizeof(double));
    }
    assign(arr, height, width, 0.0);
    print_image(arr, height, width);
    (void)fflush(stdout);
    (void)fclose(stdout);

    cr_assert_stdout_eq_str(" \n");
    free(arr);
}
