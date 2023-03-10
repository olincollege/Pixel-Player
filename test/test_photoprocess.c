#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <unistd.h>

#include "../src/photoprocess.h"



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

// // test that a string with characters and integers is read properly
// Test(user_input, all_white_image) {
//     // get the users file directory
//     char cwd[200];
//     getcwd(cwd, sizeof(cwd));


//     cr_assert_eq(strcmp(output, "123456 abCDefG"), 0, "Output is: %s, expected: %s.", output, "123456 abCDefG");
// }

