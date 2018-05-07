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
        printf("\t Expected : %s but got %s\n", wanted == TRUE ? "TRUE" : "FALSE", res == TRUE ? "TRUE" : "FALSE");
        throw_err(FALSE);
    }
}

int main()
{
    test_number("Expecting integer - Simple", TRUE, "4", SGT_NONE, NULL);
    test_number("Expecting integer - Decimal", FALSE, "1.337", SGT_NONE, NULL);
    test_number("Expecting integer - Negative", FALSE, "-69", SGT_NONE, NULL);
    test_number("Expecting integer - Decimal and negative", FALSE, "-1.23", SGT_NONE, NULL);
    test_number("Expecting integer - Not a number", FALSE, "ding", SGT_NONE, NULL);

    test_number("Expecting relative - Positive", TRUE, "4", SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting relative - Negative", TRUE, "-4", SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting relative - Decimal", FALSE, "4.01", SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting relative - Neg Decimal", FALSE, "-1.234", SGT_ALLOW_NEGATIVE, NULL);

    test_number("Expecting decimal - Simple", TRUE, "4.20", SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Negative", FALSE, "-4.9", SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Allow negative", TRUE, "-7.4", SGT_ALLOW_DECIMAL | SGT_ALLOW_NEGATIVE, NULL);
    test_number("Expecting decimal - Non null", TRUE, "4", SGT_NON_NULL | SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Non null and allow negative", FALSE, "-0", SGT_NON_NULL | SGT_ALLOW_DECIMAL, NULL);
    test_number("Expecting decimal - Non null", FALSE, "0", SGT_NON_NULL | SGT_ALLOW_DECIMAL, NULL);

    customNumber_t param;

    customNumber_from_to(&param, 3, 7);
    test_number("Expecting range - Range provided but not active", TRUE, "4", SGT_NONE, &param);
    test_number("Expecting range - Range active but none provided", FALSE, "8", SGT_RANGE, NULL);

    customNumber_from_to(&param, 3, 9);
    test_number("Expecting range - Integers included", TRUE, "3", SGT_RANGE | SGT_RANGE_DOWN_INCLUDED, &param);
    test_number("Expecting range - Integers included", TRUE, "4", SGT_RANGE | SGT_RANGE_DOWN_INCLUDED, &param);

    customNumber_from_to(&param, 2.3, 2.6);
    test_number("Expecting range - Decimals", TRUE, "2.4", SGT_RANGE | SGT_ALLOW_DECIMAL, &param);
    test_number("Expecting range - Decimals", FALSE, "2.8", SGT_RANGE | SGT_ALLOW_DECIMAL, &param);

    customNumber_from_to(&param, -3, 2);
    test_number("Expecting range - Negative bound", TRUE, "1", SGT_RANGE | SGT_ALLOW_NEGATIVE, &param);
    test_number("Expecting range - Negative bound", FALSE, "-6", SGT_RANGE | SGT_ALLOW_NEGATIVE, &param);

    customNumber_from_to(&param, 0.5, 1.1);
    test_number("Expecting range - Decimal included", TRUE, "1.100000000", SGT_ALLOW_DECIMAL | SGT_RANGE | SGT_RANGE_UP_INCLUDED, &param);
    test_number("Expecting range - Decimal included", FALSE, "0.5", SGT_ALLOW_DECIMAL | SGT_RANGE | SGT_RANGE_UP_INCLUDED, &param);

    customNumber_from_to(&param, -7.7, 8.8);
    test_number("Expecting range - Relative decimal", TRUE, "4.5", SGT_ALLOW_DECIMAL | SGT_RANGE, &param);
    test_number("Expecting range - Relative decimal", FALSE, "-74.2", SGT_ALLOW_DECIMAL | SGT_RANGE, &param);


}