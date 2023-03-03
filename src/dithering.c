#include "dithering.h"
#include <stdio.h>
// nc is the number of colors per rgb channel

double double_round(double num) {
    if ((num - (double) ((int) num)) >= 0.50 ) {
        return (double) ((int) num + 1);
    }

    return (double) ((int) num);
}

double get_new_value(double old_val) {
    return (double_round(old_val))  / (255.0);
}

void dither (double img[HEIGHT][WIDTH]) {
    
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            double old_value = img[row][col];
            double new_value = get_new_value(old_value);
            double error = old_value - new_value;
            // printf("error: %f\n", error);
            if(error < 0) {
                error = -1*error;
            }
            // ignoring border pixels for now
            if (col < (WIDTH - 1)) {
                img[row][col + 1] += (error * (7/16));
            }

            if (row < (HEIGHT - 1)) {
                if (col > 0) {
                    img[row][col - 1] += (error * (3/16));
                }
                img[row + 1][col] += (error * (5/16));
                if (col < (WIDTH - 1)) {
                    img[row + 1][col + 1] += (error/16);
                }
            }

        }
    }
}

void print_image(double img[HEIGHT][WIDTH]) {
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            if (img[row][col] > 127.5) {
                printf(".");
            } else {
                printf(" ");
            }
            // printf("%f ", img[row][col]);
        }
        printf("\n");
    }
}

int main(void) {

    double img[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 255, 0, 0, 255, 0},
        {0, 255, 0, 0, 255, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 255, 255, 255, 255, 0},
        {0, 0, 0, 0, 0, 0}
    };

    dither(img);

    // printing the dithered image, haven't tested bc need image matrix
    print_image(img);
}
