#include "../src/dithering.c"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>


// Testing double_round

// Rounding a double with a decimal less than 5 returns the double w/o the decimal
Test(round, round_down) {
    double num = 5.321;
    double newNum = double_round(num);
    cr_assert_eq(newNum, 5.0);

}

// Rounding a double with a decimal greater than 5 returns the number + 1 as a double
Test(round, round_up) {
    double num = 5.6;
    double newNum = double_round(num);
    cr_assert_eq(newNum, 6.0);
}

// Rounding a double with a decimal = to 5 returns the number + 1 as a double
Test(round, round_point_five) {
    double num = 5.5;
    double newNum = double_round(num);
    cr_assert_eq(newNum, 6.0);
}

// Rounding a double with no decimal portion just returns that number
Test(round, stays_same) {
    double num = 5.0;
    double newNum = double_round(num);
    cr_assert_eq(newNum, 5.0);
}

// Testing get_new_value (255) = 1
Test(new_value, two_five_five) {
    double num = 255.0;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 1.0);
}

// Testing get_new_value (255.1) = 1
Test(new_value, two_five_five_one) {
    double num = 255.1;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 1.0);
}

// Testing get_new_value (51) = 0.2 
Test(new_value, five_one) {
    double num = 51;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 0.2);
}
// Testing get_new_value (50.8) = 0.2 
Test(new_value, five_zero_eight) {
    double num = 50.8;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 0.2);
}

// Testing get_new_value (51.3) = 0.2 
Test(new_value, five_one_three) {
    double num = 51.3;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 0.2);
}

// test a value > 255, returns a value > 1
// test get_new_value (510) = 2.0
Test(new_value, five_one_zero) {
    double num = 510;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 2.0);
}

// test get_new_value (510.1) = 2.0
Test(new_value, five_one_zero_one) {
    double num = 510.1;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 2.0);
}

// test get_new_value (509.5) = 2.0
Test(new_value, five_zero_nine_five) {
    double num = 509.5;
    double newNum = get_new_value(num);
    cr_assert_eq(newNum, 2.0);
}
// Testing dither
