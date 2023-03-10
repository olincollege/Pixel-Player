#pragma once

/*
 * Gets the nearest pixel value, which is the current pixel value divided by 255, rounded
 * 
 * @param old_val: A double representing the current pixel value
 * @return A double representing the new pixel value, which is the old pixel value divided by 255, rounded
 */
double get_new_value (double old_val);

void dither (double** img, int height, int width);
void print_image (double** img, int height, int width);
