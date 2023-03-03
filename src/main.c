#include <sys/ioctl.h>
#include <stdio.h>
//#include "photoprocess.c"
//#include "isa_file.c"

int main(void){
    //Find the terminal size
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    //Load photo 

    //Convert photo to array

    //Convert array to printed output!

}
