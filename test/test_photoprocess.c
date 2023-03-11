#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <string.h>

#include "../src/photoprocess.h"


// define functions needed in the tests
char *strremove(char *str, const char *sub) {
    size_t len = strlen(sub);
    if (len > 0) {
        char *p = str;
        while ((p = strstr(p, sub)) != NULL) {
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }
    return str;
}


// tests for user_input()

// test that an all character user input is read properly
Test(user_input, all_char_input) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "abcdefghijklmnopqrstuvWXYZ\n");
  (void)fclose(stdin_file);
  // redirect the user input
  (void)freopen ("nul", "w", stdout);
  const char* output = user_input();
  (void)fclose(stdout);
  cr_assert_eq(strcmp(output, "abcdefghijklmnopqrstuvWXYZ"), 0, "Output is: %s, expected: %s.", output, "abcdefghijklmnopqrstuvWXYZ");
}

// test that an all integer user input is read properly
Test(user_input, all_int_input) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "123456\n");
  (void)fclose(stdin_file);
  // redirect the user input
  (void)freopen ("nul", "w", stdout);
  const char* output = user_input();
  (void)fclose(stdout);
  cr_assert_eq(strcmp(output, "123456"), 0, "Output is: %s, expected: %s.", output, "123456");
}

// test that a string with characters and integers is read properly
Test(user_input, all_int_char_input) {
  FILE* stdin_file = cr_get_redirected_stdin();
  (void)fprintf(stdin_file, "123456 abCDefG\n");
  (void)fclose(stdin_file);
  // redirect the user input
  (void)freopen ("nul", "w", stdout);
  const char* output = user_input();
  (void)fclose(stdout);
  cr_assert_eq(strcmp(output, "123456 abCDefG"), 0, "Output is: %s, expected: %s.", output, "123456 abCDefG");
}


// test for load_resize_image()


// define the user's image path

// test that a string with characters and integers is read properly
Test(user_input, all_white_image) {
    // define an all white image array
    double expected[3][3] = {{255, 255, 255},
                             {255, 255, 255},
                             {255, 255, 255}};

    // get the users file directory
    char cwd[400];
    getcwd(cwd, sizeof(cwd));

    // remove the build reference from the directory
    strremove(cwd, "/build");
    
    char* image_path = "/img/3x3blacksquare.png";

    // combine the image location with the working directory
    strncat(cwd, image_path, sizeof(cwd));

    puts("moshi moshi");

    // load the image
    double** image = load_resize_image(cwd, 3, 3);

    // cast the image to an array since sizeof is returning the size of the pointer

    printf("size of image is %d\n", (int)sizeof(image));
    printf("size of the all_white_image is %d\n", (int)sizeof(expected));

    cr_assert_arr_eq_cmp(image, expected, sizeof(double **));
}

