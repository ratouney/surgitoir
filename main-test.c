/*
** EPITECH PROJECT, 2018
** lskjfs
** File description:
** sldkfjs
*/

#include <stdio.h>
#include "surgitoir.h"

int test_total = 0;
int test_passed = 0;

void test_number(char *msg, bool_t wanted, char *num, number_opts_t opt, customNumber_t *param)
{
    bool_t res;
    test_total++;

    res = check_number(num, opt, param);
    if (res == wanted) {
        test_passed++;
        printf("\e[32mPassed\e[0m : %s\n", msg);
    } else {
        printf("\e[31mFail\e[0m :   %s ==> [%s]\n", msg, num);
        printf("\t Expected : %s but got %s\n", wanted == SGT_TRUE ? "SGT_TRUE" : "SGT_FALSE", res == SGT_TRUE ? "SGT_TRUE" : "SGT_FALSE");
        throw_err(SGT_FALSE);
    }
}

int main()
{
    test_number("Expecting integer - Simple", SGT_TRUE, "4", SGT_ANY, NULL);
    test_number("Expecting integer - Decimal", SGT_FALSE, "1.337", SGT_ANY, NULL);
    test_number("Expecting integer - Negative", SGT_FALSE, "-69", SGT_ANY, NULL);
    test_number("Expecting integer - Decimal and negative", SGT_FALSE, "-1.23", SGT_ANY, NULL);
    test_number("Expecting integer - Not a number", SGT_FALSE, "ding", SGT_ANY, NULL);

    test_number("Expecting relative - Positive", SGT_TRUE, "4", SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting relative - Negative", SGT_TRUE, "-4", SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting relative - Decimal", SGT_FALSE, "4.01", SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting relative - Neg Decimal", SGT_FALSE, "-1.234", SGT_ALLOW_NEGATIVE, NULL);

    test_number("Expecting decimal - Simple", SGT_TRUE, "4.20", SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Negative", SGT_FALSE, "-4.9", SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Allow negative", SGT_TRUE, "-7.4", SGT_ALLOW_DECIMAL | SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting decimal - Non null", SGT_TRUE, "4", SGT_NON_NULL | SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Non null and allow negative", SGT_FALSE, "-0", SGT_NON_NULL | SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Non null", SGT_FALSE, "0", SGT_NON_NULL | SGT_ALLOW_DECIMAL, NULL);

    customNumber_t param;

    customNumber_from_to(&param, 3, 7);
    test_number("Expecting range - Range provided but not active", SGT_TRUE, "4", SGT_ANY, &param);
    test_number("Expecting range - Range active but none provided", SGT_FALSE, "8", SGT_RANGE, NULL);

    customNumber_from_to(&param, 3, 9);
    test_number("Expecting range - Integers included", SGT_TRUE, "3", SGT_RANGE | SGT_RANGE_DOWN_INCLUDED, &param);
    test_number("Expecting range - Integers included", SGT_TRUE, "4", SGT_RANGE | SGT_RANGE_DOWN_INCLUDED, &param);

    customNumber_from_to(&param, 2.3, 2.6);
    test_number("Expecting range - Decimals", SGT_TRUE, "2.4", SGT_RANGE | SGT_ALLOW_DECIMAL, &param);
    test_number("Expecting range - Decimals", SGT_FALSE, "2.8", SGT_RANGE | SGT_ALLOW_DECIMAL, &param);

    customNumber_from_to(&param, -3, 2);
    test_number("Expecting range - Negative bound", SGT_TRUE, "1", SGT_RANGE | SGT_ALLOW_NEGATIVE, &param);
    test_number("Expecting range - Negative bound", SGT_FALSE, "-6", SGT_RANGE | SGT_ALLOW_NEGATIVE, &param);

    customNumber_from_to(&param, 0.5, 1.1);
    test_number("Expecting range - Decimal included", SGT_TRUE, "1.100000000", SGT_ALLOW_DECIMAL | SGT_RANGE | SGT_RANGE_UP_INCLUDED, &param);
    test_number("Expecting range - Decimal included", SGT_FALSE, "0.5", SGT_ALLOW_DECIMAL | SGT_RANGE | SGT_RANGE_UP_INCLUDED, &param);

    customNumber_from_to(&param, -7.7, 8.8);
    test_number("Expecting range - Relative decimal", SGT_TRUE, "4.5", SGT_ALLOW_DECIMAL | SGT_RANGE, &param);
    test_number("Expecting range - Relative decimal", SGT_FALSE, "-74.2", SGT_ALLOW_DECIMAL | SGT_RANGE, &param);


}