#pragma once

/**
 * Read a user input from the terminal
 *
 * For as long as the user provides an input, record the corresponding
 * string into the heap memory. Memory is dynamically allocated depending
 * on the length of the user input. 
 *
 * @return a string in heap memory representing the user input
 */
char* user_input(void);


/**
 * Load a png or jpg image given a file path and resize to specified dimensions.
 *
 * Given a string representing the file path to a png or jpg image. This code
 * will load the image as a grayscale unsigned char. Then it will convert
 * the chars to an array of arrays, with each unsigned integer representing
 * a 0 to 255 grayscale value. The array is resized to the width and 
 * height specified by the user.
 *
 * @param file_path a string representing the file path to a jpg or png image.
 * @param t_width an unsigned integer representing the desired width of the output.
 * @param t_height an unsigned integer representing the desired height of the output.
 * @return an unsigned integer array of arrays, representing the grayscale values of an image.
 */
unsigned int** load_resize_image(char* file_path, unsigned int t_width, unsigned int t_height);


/**
 * Clears the heap memory allocated in load_resize_image and user_input.
 *
 * Uses free to free the memory allocated by user_input for the file_path and
 * image_array in load_resize_image. It requires the height of the image in
 * order to loop through and free the arrays nested in the array of arrays.
 *
 * @param file_path a string representing the file path to a .png or .jpg image
 * @param image_array an unsigned integer array of arrays, representing a grayscale image
 * @param image_height an integer representing the height (# of rows) of image_array
 */
void clear_memory(char* file_path, unsigned int** image_array, unsigned int image_height);
