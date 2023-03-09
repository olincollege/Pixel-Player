#include "dithering.h"
#include <stdio.h>
#include <math.h>

double get_new_value(double old_val) {
    // round returns an int??
    return (double) (round(old_val  / (255.0)));
}

void dither (double** img, int height, int width) {

    for(int row = 0; row < height; row++) {
        // double row_array = img[row];
        for(int col = 0; col < width; col++) {
            // printf("%d\n", sizeof(img)/sizeof(img[0]));
            double old_value = img[row][col]/255.;
            // printf("%f ", old_value);
            double new_value = get_new_value(old_value);
            // printf("new: %f \n", new_value);
            // img[row][col] = 
            double error = old_value - new_value;
            // printf("error %f \n", error);
            // ignoring border pixels 
            if (col < (width - 1)) {
                // printf("%f\n", (error * (7./16.)));
                img[row][col + 1] += (new_value * (7./16.));
            }

            if (row < (height - 1)) {
                if (col > 0) {
                    img[row][col - 1] += (error * (3./16.));
                }
                img[row + 1][col] += (error * (5./16.));
                if (col < (width - 1)) {
                    img[row + 1][col + 1] += (error/16.);
                }
            }

        }
    }
    // printf("here\n");
    // print_image(img, height, width);
}


void print_image(double** img, int height, int width) {
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {

            if(img[row][col] >= 127.5) {
                printf(" ");
            } else {
                printf("$");
            }
            // printf("%f ", img[row][col]);
        }
        printf("\n");
    }
}
