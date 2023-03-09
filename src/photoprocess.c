// load the needed libraries
#include "stb_image.h"
#include "stb_image_resize.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* user_input(void){
    // define the storage size to allocate 
    unsigned int len_max = 128;
    // define a variable to track the size of the current user's input
    unsigned int current_size = 0;
    
    // allocate the memory to store the user's input
    char *pStr = malloc(len_max);
    // define the allowable current input limit as len_max
    current_size = len_max;

    printf("\nPlease Enter a File Path to a .png or .jpg File: ");

    if(pStr != NULL)
    {
	int c = EOF;
	unsigned int i = 0;

    //accept user input until hit enter or end of file
	while (( c = getchar() ) != '\n' && c != EOF)
	{
        // assign the input character to memory
		pStr[i++]=(char)c;

		//if i reached maximize size then realloc size
		if(i == current_size)
		{
            // update the maximum amount of memory to allocate
            current_size = i+len_max;
            // allocate the new memory with our string
			pStr = realloc(pStr, current_size);
		}
	}

    // add an ending character to the end
	pStr[i] = '\0';

    // return the pointer to the user input
    return(pStr);
}
}

unsigned int** load_resize_image(const char* file_path, unsigned int t_width, unsigned int t_height){
    // create the variables to store the original photo properties
    int width;
    int height;
    int channels;

    // create a character array to store the resized image
    unsigned char resized_img[t_width*t_height];

    // create the integer array to store the final output
    // allocate the first level (rows)
    unsigned int ** image_array = (unsigned int **)malloc(t_height*sizeof(unsigned int*));

    // allocate the second level
    for (unsigned int i = 0; i < t_height; i++) {
        image_array[i] = (unsigned int *) malloc(t_width*sizeof(unsigned int));
    }

    // load the image from the file path, specify 1 to only load the grey values
    unsigned char* img = stbi_load(file_path, &width, &height, &channels, 1);

    // if the load failed it will return NULL, so exit the code
    if (img == NULL){
        puts("Error in loading the image! Remember to provide the full file path");
        exit(1);
    }

    // resize the image to the user terminal dimensions
    (void)stbir_resize_uint8(img , width , height , 0,
                               resized_img, t_width, t_height, 0, 1);

    // loop through each of the pixel values and add them to the array
    // remember arrays start at 0,0
    // refer to this https://www.geeksforgeeks.org/multidimensional-arrays-c-cpp/


    for (size_t i = 0; i < t_width*t_height; i++){
        // store the pixel in its proper place
        image_array[i / t_width][i % t_width] = (int)(resized_img[i]);
    }

    // return the array of arrays
    return(image_array);

}

void clear_memory(const char* file_path, unsigned int** image_array, unsigned int image_height){
    // clear all of the mallocs from memory

    // free the file path first
    free(file_path);

    // since image array is a double pointer, we first have to loop through
    // and free each row before free image_array itself
    for (unsigned int i = 0; i < image_height; i++){
        free(image_array[i]);
    }

    free(image_array);

}





