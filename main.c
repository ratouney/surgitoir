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

    test_number("Expecting  - ", FALSE, "ding", SGT_NONE, NULL);

}