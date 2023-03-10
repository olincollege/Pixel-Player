// #include "extern_define.h"
#include "dithering.h"
#include "photoprocess.h"
#include "stb_image.h"
#include "stb_image_resize.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>


int main(void){
    //Find the terminal size
    struct winsize window;
    ioctl(0, TIOCGWINSZ, &window);

    // prompt the user for a file path
    //const char* file_path = user_input();

    char* file_path = user_input();
 

    // load the image
    double** image_array = load_resize_image(file_path, window.ws_col, window.ws_row);

    dither(image_array, window.ws_row, window.ws_col);
    print_image(image_array, window.ws_row, window.ws_col);


    // do not run if file path is hard coded
    clear_memory(file_path, image_array, (unsigned int)window.ws_row);
    
    return 0;
}
