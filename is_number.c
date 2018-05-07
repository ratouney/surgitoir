/*
** EPITECH PROJECT, 2018
** lxsdkjf
** File description:
** sldkfj
*/

#include "surgitoir.h"

bool_t is_num(char *str)
{
    char *init = str;
    char minus = 0;
    char plus = 0;
    char dot = 0;

    if (str == NULL || str[0] == 0)
        return SGT_FALSE;
    while (str[0] == ' ')
        str++;
    for (int i = 0; str[i] != 0 ; i++) {
        switch(str[i]) {
            case ' ':
                return sgt_error_assign(init, INVALID_WHITESPACE);
            case '.':
                if (dot == 0) {
                    dot++;
                    break;
                } else {
                    return sgt_error_assign(init, MULTIPLE_FLOATING_POINTS);
                }
            case '-':
                if (i > 0 && is_in("0123456789.", str[i - 1]) == SGT_TRUE)
                    return sgt_error_assign(init, FLYING_MINUS);
                if (minus == 0) {
                    minus++;
                    break;
                } else {
                    return sgt_error_assign(init, MULTIPLE_MINUSES);
                }
            case '+':
                if (i > 0 && is_in("0123456789.", str[i - 1]) == SGT_TRUE)
                    return sgt_error_assign(init, FLYING_PLUS);
                if (plus == 0) {
                    plus++;
                    break;
                } else {
                    return sgt_error_assign(init, MULTIPLE_PLUSES);
                }
            default:
                if (is_in("0123456789", str[i]) == SGT_FALSE) {
                    return SGT_FALSE;
                }
        }
    }
    return SGT_TRUE;
}