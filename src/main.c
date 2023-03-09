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

    // prompt the user for a file path
    //const char* file_path = user_input();

    const char* file_path = user_input();
    
    // store the resize width and height according to the user terminal
    unsigned int resize_width = w.ws_col;
    unsigned int resize_height = w.ws_row;

    
    // load the image
    unsigned int** image_array = load_resize_image(file_path, resize_width, resize_height);
    
    dither(image_array, resize_height, resize_width);
    print_image(image_array, resize_height, resize_width);



    // do not run if file path is hard coded
    clear_memory(file_path, image_array, (unsigned int)(w.ws_row));
    
    return 0;

}
