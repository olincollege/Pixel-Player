#include <sys/ioctl.h>
#include <stdio.h>
#include "stb_image.h"
#include "stb_image_resize.h"
#include "photoprocess.c"

int main(void){
    //Find the terminal size
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    //Load photo 

    //Convert photo to array

    //Convert array to printed output!


    // prompt the user for a file path
    //const char* file_path = user_input();
    const char* file_path = "/home/phillip/github/Pixel-Player/src/img/test.png";

    // initialize variables to store the image parameters
    int width, height, channels;

    printf("%s\n", file_path);

    // load the image from the file path, specify 1 to only load the grey values
    unsigned char* img = stbi_load(file_path, &width, &height, &channels, 1);

    // if the load failed it will return NULL, so exit the code
    if (img == NULL){
        puts("Error in loading the image!");
        exit(1);
    }

    // create an array to store the pixel values
    unsigned int image_array[height][width];

    // loop through each of the pixel values and add them to the array
    // remember arrays start at 0,0
    // refer to this https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/

    for (size_t i = 0; i < width*height; i++){
        // store the pixel in its proper place
        image_array[i / width][i % width] = (int)(img[i]);
    }


}
