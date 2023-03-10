#include <sys/ioctl.h>
#include <stdio.h>
// #include "extern_define.h"
#include "stb_image.h"
#include "stb_image_resize.h"
#include "photoprocess.c"
#include "dithering.h"
#include <stdlib.h>
#include <unistd.h>


int main(void){
    //Find the terminal size
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    // prompt the user for a file path
    //const char* file_path = user_input();

    const char* file_path = user_input();

    

    
    // load the image
    unsigned int** image_array = load_resize_image(file_path, (unsigned int)w.ws_col, (unsigned int)w.ws_row);

    dither(image_array, (unsigned int)w.ws_row, (unsigned int)w.ws_col);
    print_image(image_array, (unsigned int)w.ws_row, (unsigned int)w.ws_col);



    // do not run if file path is hard coded
    clear_memory(file_path, image_array, (unsigned int)w.ws_row);
    
    return 0;

}
