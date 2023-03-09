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

    unsigned int** image_array = load_resize_image(file_path, (unsigned int)(w.ws_col), (unsigned int)(w.ws_row));


    

    // print a test representation of the image
    for (size_t j = 0; j < w.ws_row; j++){

    for (size_t i = 0; i < w.ws_col; i++){
        if (i == w.ws_col - 1){
            printf("%d\n", image_array[j][i] % 2);
        } else {
            printf("%d", image_array[j][i] % 2);
        }

    }
    }

    // do not run if file path is hard coded
    //clear_memory(file_path, image_array, (unsigned int)(w.ws_row));
}
