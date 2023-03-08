#include <sys/ioctl.h>
#include <stdio.h>
// #include "extern_define.h"
#include "stb_image.h"
#include "stb_image_resize.h"
#include "photoprocess.c"
#include "dithering.h"
#include <stdlib.h>


int main(void){
    //Find the terminal size
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    //Load photo 

    //Convert photo to array

    //Convert array to printed output!


    // prompt the user for a file path
    //const char* file_path = user_input();
    const char* file_path = "/home/newHomeDir/Pixel-Player/src/img/testimg.png";

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

    // store the resize width and height according to the user terminal
    int resize_width = w.ws_col;
    int resize_height = w.ws_row;

    // create a character array to store the resized image
    unsigned char output_pixels[resize_width*resize_height];

    // resize the image to the user terminal
    (void)stbir_resize_uint8(img , width , height , 0,
                               output_pixels, resize_width, resize_height, 0, 1);

    // create an array to store the pixel values sized to the user terminal
    double **image_array = (double **)malloc(resize_height* sizeof(double *));
    for(int i = 0; i < resize_width; i++){
        image_array[i] = (double*)malloc(resize_width * sizeof(double));
    }
    // loop through each of the pixel values and add them to the array
    // remember arrays start at 0,0
    // refer to this https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/

    for (size_t i = 0; i < resize_width*resize_height; i++){
        // store the pixel in its proper place

        image_array[i / resize_width][i % resize_width] = (double)(int)(output_pixels[i]);
    }
    // print_image(image_array, resize_height, resize_width);
    // height = resize_height;
    // width = resize_width;
    // double* first_pointer = &image_array;
    // printf("%f", resize_height);
    // printf("about to dither \n");
    
    dither(image_array, resize_height, resize_width);
    print_image(image_array, resize_height, resize_width);
    free(image_array);
    return 0;
}
