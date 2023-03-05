#include "dithering.h"
#include <stdio.h>
#include <math.h>
// nc is the number of colors per rgb channel

// double double_round(double* num) {
//     if ((num - (double) ((int) num)) >= 0.50 ) {
//         return (double) ((int) num + 1);
//     }

//     return (double) ((int) num);
// }

double get_new_value(double old_val) {
    // round returns an int??
    return (double) (round(old_val)  / (255.0));
}

void dither (double** img, int height, int width) {
    // printf("about to enter for loop\n");
    // printf("here\n");
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            // printf("at top of 2nd loop");
            double old_value = img[row][col];
            double new_value = get_new_value(old_value);
            double error = old_value - new_value;
            // // printf("error: %f\n", error);
            if(error < 0) {
                error = -1*error;
            }
            // ignoring border pixels for now
            if (col < (width - 1)) {
                img[row][col + 1] += (error * (7/16));
            }

            if (row < (height - 1)) {
                if (col > 0) {
                    img[row][col - 1] += (error * (3/16));
                }
                img[row + 1][col] += (error * (5/16));
                if (col < (width - 1)) {
                    img[row + 1][col + 1] += (error/16);
                }
            }

        }
    }
    // printf("here\n");
    print_image(img, height, width);
}

void print_image(double** img, int height, int width) {
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if (img[row][col] >= 127.5) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// int main(void) {

//     double* img[6][6] = {
//         {0, 0, 0, 0, 0, 0},
//         {0, 255, 0, 0, 255, 0},
//         {0, 255, 0, 0, 255, 0},
//         {0, 0, 0, 0, 0, 0},
//         {0, 255, 255, 255, 255, 0},
//         {0, 0, 0, 0, 0, 0}
//     };
//     int height = 6;
//     int width = 6;

//     dither(img, height, width);

//     // printing the dithered image, haven't tested bc need image matrix
//     // print_image(img, 6, 6);
// }
