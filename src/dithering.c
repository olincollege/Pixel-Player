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
}


void print_image(double** img, int height, int width) {
    const double space = 3.64;
    const double period = 7.28;
    const double apos = 10.92;
    const double accent = 14.56;
    const double carrot = 18.2;
    const double quotation = 21.84;
    const double comma = 25.48;
    const double colon = 29.12;
    const double semicolon = 32.76;
    const double capeye = 36.4;
    const double elle = 40.04;
    const double exclamation = 43.68;
    const double loweye = 47.32;
    const double greater = 50.96;
    const double less = 54.6;
    const double tilda = 58.24;
    const double plus = 61.88;
    const double underscore = 65.52;
    const double dash = 69.16;
    const double question = 72.8;
    const double closebrack = 76.44;
    const double openbrack = 80.08;
    const double closecurl = 83.72;
    const double opencurl = 87.36;
    const double one = 91;
    const double openparan = 94.64;
    const double closeparan = 98.28;
    const double upright = 101.92;
    const double backslash = 105.56;
    const double slash = 109.2;
    const double lowtee = 112.84;
    const double loweff = 116.48;
    const double lowjay = 120.12;
    const double lowr = 123.76;
    const double lowx = 127.4;
    const double lown = 131.04;
    const double lowu = 134.68;
    const double lowv = 138.32;
    const double lowc = 141.96;
    const double lowz = 145.6;
    const double upperx = 149.24;
    const double uppery = 152.88;
    const double upperu = 156.52;
    const double upperj = 160.16;
    const double upperc = 163.8;
    const double upperl = 167.44;
    const double upperq = 171.08;
    const double zero = 174.72;
    const double uppero = 178.36;
    const double upperz = 182;
    const double lowerm = 185.64;
    const double lowerw = 189.28;
    const double lowerq = 192.92;
    const double lowerp = 196.56;
    const double lowerd = 200.2;
    const double lowerb = 203.84;
    const double lowerk = 207.48;
    const double lowerh = 211.12;
    const double lowera = 214.76;
    const double lowero = 218.4;
    const double star = 222.04;
    const double hash = 225.68;
    const double upperm = 229.32;
    const double upperw = 232.96;
    const double amp = 236.6;
    const double eight = 240.24;
    const double per = 243.88;
    const double upperb = 247.52;
    const double ats = 251.16;
    const double dollar = 254.8;

    const int seventy = 70;

    const int characters[70] = {' ', '.', '\'', '`', '^', '"', ',', ':', ';', 'I', 'l', '!', 'i', '>', '<', '~', '+', '_',
                                  '-', '?', ']', '[', '}', '{', '1', ')', '(', '|', '\\', '/', 't', 'f', 'j', 'r', 'x', 'n',
                                  'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', 'O', 'Z', 'm', 'w', 'q', 'p',
                                  'd', 'b', 'k', 'h', 'a', 'o', '*', '#', 'M', 'W', '&', '8', '%', 'B', '@', '$'};
    double limits[70] = {space, period, apos, accent, carrot, quotation, comma, colon, semicolon, capeye, elle, exclamation, 
                         loweye, greater, less, tilda, plus, underscore, dash, question, closebrack, openbrack, closecurl, 
                         opencurl, one, openparan, closeparan, upright, backslash, slash, lowtee, loweff, lowjay, lowr, lowx, 
                         lown, lowu, lowv, lowc, lowz, upperx, uppery, upperu, upperj, upperc, upperl, upperq, zero, uppero, 
                         upperz, lowerm, lowerw, lowerq, lowerp, lowerd, lowerb, lowerk, lowerh, lowera, lowero, star, hash, 
                         upperm, upperw, amp, eight, per, upperb, ats, dollar};
    // const double lowc 
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            for(int i = 0; i < seventy; i++) {
                if(img[row][col] <= limits[i]) {
                    printf("%c", characters[i]);
                    break;
                }
                
            }
        }
        printf("\n");
    }
}

