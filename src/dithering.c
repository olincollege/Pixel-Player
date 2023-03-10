#include "dithering.h"
#include <math.h>
#include <stdio.h>



double get_new_value(double old_val) {
    const double white = 255.0;
    return (round(old_val  / (white)));
}

void dither (double** img, int height, int width) {
    const double white = 255.0;
    const double seven = 7.0;
    const double sixteen = 16.0;
    const double three = 3.0;
    const double five = 5.0;
    for(int row = 0; row < height; row++) {
        // double row_array = img[row];
        for(int col = 0; col < width; col++) {
            // printf("%d\n", sizeof(img)/sizeof(img[0]));
            double old_value = img[row][col]/white;
            // printf("%f ", old_value);
            double new_value = get_new_value(old_value);
            // printf("new: %f \n", new_value);
            // img[row][col] = 
            double error = old_value - new_value;
            // printf("error %f \n", error);
            // ignoring border pixels 
            if (col < (width - 1)) {
                // printf("%f\n", (error * (7./16.)));
                img[row][col + 1] += (new_value * (seven/sixteen));
            }

            if (row < (height - 1)) {
                if (col > 0) {
                    img[row][col - 1] += (error * (three/sixteen));
                }
                img[row + 1][col] += (error * (five/sixteen));
                if (col < (width - 1)) {
                    img[row + 1][col + 1] += (error/sixteen);
                }
            }

        }
    }
    // printf("here\n");
    // print_image(img, height, width);
}


void print_image(double** img, int height, int width) {
    const double space = 3.64;
    const double period = 7.28;
    const double apos = 10.92;
    const double accent = 14.56;
    const double carrot = 18.2;
    const double backslash = 21.84;
    const double comma = 25.48;
    const double colon = 29.12;
    const double semicolon = 32.76;
    const double capeye = 36.4;
    const double elle = 40.4;
    const double exclamation = 43.68;

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(img[row][col] <= space) {printf(" ");} 
            else if(img[row][col] <= period) {printf(".");}
            else if(img[row][col] <= apos) {printf("'");}
            else if(img[row][col] <= accent) {printf("`");}
            else if(img[row][col] <= carrot) {printf("^");}
            else if(img[row][col] <= backslash) {printf("\"");}
            else if(img[row][col] <= comma) {printf(",");}
            else if(img[row][col] <= colon) {printf(":");}
            else if(img[row][col] <= semicolon) {printf(";");}
            else if(img[row][col] <= capeye) {printf("I");}
            else if(img[row][col] <= elle) {printf("l");}
            else if(img[row][col] <= exclamation) {printf("!");}
            else if(img[row][col] <= 47.32) {printf("i");}
            else if(img[row][col] <= 50.96) {printf(">");}
            else if(img[row][col] <= 54.6) {printf("<");}
            else if(img[row][col] <= 58.24) {printf("~");}
            else if(img[row][col] <= 61.88) {printf("+");}
            else if(img[row][col] <= 65.52) {printf("_");}
            else if(img[row][col] <= 69.16) {printf("-");}
            else if(img[row][col] <= 72.8) {printf("?");}
            else if(img[row][col] <= 76.44) {printf("]");}
            else if(img[row][col] <= 80.08) {printf("[");}
            else if(img[row][col] <= 83.72) {printf("}");}
            else if(img[row][col] <= 87.36) {printf("{");}
            else if(img[row][col] <= 91) {printf("1");}
            else if(img[row][col] <= 94.64) {printf(")");} 
            else if(img[row][col] <= 98.28) {printf("(");}
            else if(img[row][col] <= 101.92) {printf("|");}
            else if(img[row][col] <= 105.56) {printf("\\");}
            else if(img[row][col] <= 109.2) {printf("/");}
            else if(img[row][col] <= 112.84) {printf("t");}
            else if(img[row][col] <= 116.48) {printf("f");}
            else if(img[row][col] <= 120.12) {printf("j");}
            else if(img[row][col] <= 123.76) {printf("r");}
            else if(img[row][col] <= 127.4) {printf("x");}
            else if(img[row][col] <= 131.04) {printf("n");}
            else if(img[row][col] <= 134.68) {printf("u");}
            else if(img[row][col] <= 132.32) {printf("v");}
            else if(img[row][col] <= 141.96) {printf("c");}
            else if(img[row][col] <= 145.6) {printf("z");}
            else if(img[row][col] <= 149.24) {printf("X");}
            else if(img[row][col] <= 152.88) {printf("Y");}
            else if(img[row][col] <= 156.52) {printf("U");}
            else if(img[row][col] <= 160.16) {printf("J");}
            else if(img[row][col] <= 163.8) {printf("C");}
            else if(img[row][col] <= 167.44) {printf("L");}
            else if(img[row][col] <= 171.08) {printf("Q");}
            else if(img[row][col] <= 174.72) {printf("0");}
            else if(img[row][col] <= 178.36) {printf("O");}
            else if(img[row][col] <= 182) {printf("Z");}
            else if(img[row][col] <= 185.64) {printf("m");}
            else if(img[row][col] <= 189.28) {printf("w");}
            else if(img[row][col] <= 192.92) {printf("q");}
            else if(img[row][col] <= 196.56) {printf("p");}
            else if(img[row][col] <= 200.2) {printf("d");}
            else if(img[row][col] <= 203.84) {printf("b");}
            else if(img[row][col] <= 207.48) {printf("k");}
            else if(img[row][col] <= 211.12) {printf("h");}
            else if(img[row][col] <= 214.76) {printf("a");}
            else if(img[row][col] <= 218.4) {printf("o");}
            else if(img[row][col] <= 222.04) {printf("*");}
            else if(img[row][col] <= 225.68) {printf("#");}
            else if(img[row][col] <= 229.32) {printf("M");}
            else if(img[row][col] <= 232.96) {printf("W");}
            else if(img[row][col] <= 236.6) {printf("&");}
            else if(img[row][col] <= 240.24) {printf("8");}
            else if(img[row][col] <= 243.88) {printf("%%");}
            else if(img[row][col] <= 247.52) {printf("B");}
            else if(img[row][col] <= 251.16) {printf("@");}
            else {printf("$");}
            // printf("%f ", img[row][col]);
        }
        printf("\n");
    }
}

