#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string.h>
#include <unistd.h>

#include "../src/photoprocess.h"


// define functions needed in the tests

// function for removing a substring from a string
char *strremove(char *str, const char *sub) {
    size_t len = strlen(sub);
    if (len > 0) {
        char *pit = str;
        while ((pit = strstr(pit, sub)) != NULL) {
            memmove(pit, pit + len, strlen(pit + len) + 1);
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
const int input_size = 400;
const int array_vals = 9;



// test that an all white image is loaded properly
Test(user_input, all_white_image) {
    const int white = 255;

    // define an all white image array
    double expected[3][3] = {{white, white, white},
                             {white, white, white},
                             {white, white, white}};

    // get the users file directory
    char cwd[input_size];
    getcwd(cwd, sizeof(cwd));

    // remove the build reference from the directory
    strremove(cwd, "/build");
    
    char* image_path = "/img/3x3whitesquare.png";

    // combine the image location with the working directory
    strcat(cwd, image_path);

    // load the image
    double** image = load_resize_image(cwd, 3, 3);

    // initialize the equal check
    int equal = 0;

    // assess if the load array is equal to the expected array
    for (int i = 0; i < array_vals; i++){
      if (image[i / 3][i % 3] != expected[i / 3][i % 3]){
        equal = 0;
        break;
      }

      // if all of the values were equal, set equal to 1
      if (i == array_vals - 1){
        equal = 1;
      }
    }

    cr_assert_eq(equal, 1, "load_resize_image is not properly loading an all white image");
}

// test that an all black image is loaded properly
Test(user_input, all_black_image) {
    int black = 0;

    // define an all black image array
    double expected[3][3] = {{black, black, black},
                             {black, black, black},
                             {black, black, black}};

    // get the users file directory
    char cwd[input_size];
    getcwd(cwd, sizeof(cwd));

    // remove the build reference from the directory
    strremove(cwd, "/build");
    
    char* image_path = "/img/3x3blacksquare.png";

    // combine the image location with the working directory
    strcat(cwd, image_path);

    // load the image
    double** image = load_resize_image(cwd, 3, 3);

    // initialize the equal check
    int equal = 0;

    // assess if the load array is equal to the expected array
    for (int i = 0; i < array_vals; i++){
      if (image[i / 3][i % 3] != expected[i / 3][i % 3]){
        equal = 0;
        break;
      }

      // if all of the values were equal, set equal to 1
      if (i == array_vals - 1){
        equal = 1;
      }
    }

    cr_assert_eq(equal, 1, "load_resize_image is not properly loading an all black image");
}


