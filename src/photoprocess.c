// load the needed libraries
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
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



void main(void) {
    // prompt the user for a file path
    const char* file_path = user_input();

    // initialize variables to store the image parameters
    int width, height, channels;

    // load the image from the file path, specify 1 to only load the grey values
    unsigned char* img = stbi_load(file_path, &width, &height, &channels, 1);

    // if the load failed it will return NULL, so exit the code
    if (img == NULL){
        puts("Error in loading the image!");
        exit(1);
    }






    // free the storage for the file path
    free(file_path);



}
