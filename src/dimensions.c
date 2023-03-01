//https://medium.com/@pauljlucas/getting-the-terminal-width-in-c-48560b556575
//https://psychocod3r.wordpress.com/2019/02/25/how-to-get-the-dimensions-of-a-linux-terminal-window-in-c/
//https://stackoverflow.com/questions/1022957/getting-terminal-width-in-c
//https://www.delorie.com/djgpp/doc/libc/libc_495.html
#include <sys/ioctl.h>
#include <stdio.h>

int get_dimensions (void){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
}

int main (void)
{
    get_dimensions();
    return 0;
}
