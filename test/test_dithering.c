#include "../src/dithering.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>



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
    cr_assert(eq(get_new_value(255.0), 1.0));
}
// Check that passing zero to get_new_value returns zero
Test(test_new_value, zero) {
    cr_assert(eq(get_new_value(0.0), 0.0));
}
// check that passing a negative number to get_new_value returns a negative number
Test(test_new_value, negative_num) {
    cr_assert(eq(get_new_value(-255.0), -1.0));
}
// check that dithering an array of 0s does not alter that array
Test(test_dither, array_zeros) {
    int height = 5;
    int width = 5;
    double** arr = (double**) malloc (height * sizeof(double*));
    for(int i = 0; i < height; i++) {
        arr[i] = (double*) malloc (width * sizeof(double));
    }
    assign(arr, height, width, 0.0);

    double** expected_arr = (double**) malloc (height * sizeof(double*));
    for(int i = 0; i < height; i++) {
        expected_arr[i] = (double*) malloc (width * sizeof(double));
    }
    assign(expected_arr, height, width, 0.0);

    dither(arr, height, width);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cr_assert(eq(arr[i][j], expected_arr[i][j]));
        }
    }

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

    cr_assert_stdout_eq_str("$\n");
    free(arr);
}

// Check that printing an array of 255 prints blanks only
Test(test_print, array_blank, .init = cr_redirect_stdout) {
    int height = 1;
    int width = 1;
    double** arr = (double**) malloc (height * sizeof(double*));
    for(int i = 0; i < height; i++) {
        arr[i] = (double*) malloc (width * sizeof(double));
    }
    assign(arr, height, width, 255.0);
    print_image(arr, height, width);
    (void)fflush(stdout);
    (void)fclose(stdout);

    cr_assert_stdout_eq_str(" \n");
    free(arr);

}
