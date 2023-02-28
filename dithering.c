#include "dithering.h"

// nc is the number of colors per rgb channel

float float_round(float num) {
    if ((float) (num - (float) ((int) num)) >= .50 ) {
        return (float) ((int) num + 1);
    }

    return (float) ((int) num);
}

float get_new_value(float old_val) {
    return (float_round(old_val))  / (255.0);
}

void dither (float img[HEIGHT][WIDTH]) {
    
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            float old_value = img[row][col];
            float new_value = get_new_value(old_value);
            float error = old_value - new_value;
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

int main(void) {

    float img[2][2] = {{10.5, 20.3}, {20.8, 40.999}};

    dither(img);

}
