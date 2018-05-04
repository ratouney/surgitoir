/*
** EPITECH PROJECT, 2018
** lskjfs
** File description:
** sldkfjs
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "surgitoir.h"

bool_t is_in(char *haystack, char needle)
{
    for (int i = 0; haystack[i] ; i++)
    {
        if (haystack[i] == needle)
            return TRUE;
    }
    return FALSE;
}

bool_t is_num(char *str)
{
    char *init = str;
    char minus = 0;
    char plus = 0;
    char dot = 0;

    if (str == NULL || str[0] == 0)
        return FALSE;
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
                if (i > 0 && is_in("0123456789.", str[i - 1]) == TRUE)
                    return sgt_error_assign(init, FLYING_MINUS);
                if (minus == 0) {
                    minus++;
                    break;
                } else {
                    return sgt_error_assign(init, MULTIPLE_MINUSES);
                }
            case '+':
                if (i > 0 && is_in("0123456789.", str[i - 1]) == TRUE)
                    return sgt_error_assign(init, FLYING_PLUS);
                if (plus == 0) {
                    plus++;
                    break;
                } else {
                    return sgt_error_assign(init, MULTIPLE_PLUSES);
                }
        }
        printf("Testing : [%c]\n", str[i]);
    }
    return TRUE;
}

void throw_err(bool_t crash)
{
    if (sgt_err == NULL)
        return;
    dprintf(2, "[%s] --> %s\n", sgt_err->token, error_messages[sgt_err->code]);
    if (crash == TRUE)
        exit(exit_code);
}

void set_exit_code(int code)
{
    exit_code = code;
}

bool_t check_number(char *str, number_opts_t opt, customNumber_t range)
{
    double value;

    if (is_num(str) == FALSE)
        return FALSE;
    value = strtod(str, NULL);
    if (opt & SGT_NON_NULL) {
        if (value == 0.0)
            return sgt_error_assign(str, NULL_VALUE);
    }
    if (opt & SGT_STRICT_NEGATIVE) {
        if (value >= 0) {
            return sgt_error_assign(str, POSITIVE_NUMBER);
        }
    }
    if (value < 0.0) {
        if (opt & SGT_ALLOW_NEGATIVE) {
            ;
        } else {
            return sgt_error_assign(str, NEGATIVE_NUMBER);
        }
    }
    if (value != round(value)) {
        if (opt & SGT_ALLOW_DECIMAL) {
            ;
        } else {
            return sgt_error_assign(str, DECIMAL_NUMBER);
        }
    }
    if (opt & SGT_RANGE) {
        if (range.range_up < range.range_down) {
            return sgt_error_assign(str, INVALID_RANGE);
        }
        if (value >= range.range_up) {
            if (opt & SGT_RANGE_UP_INCLUDED) {
                if (value <= range.range_up) {
                    ;
                } else {
                    return sgt_error_assign(str, UPPER_BOUND_REACHED);
                }
            } else {
                return sgt_error_assign(str, UPPER_BOUND_REACHED);
            }
        }
        if (value <= range.range_down) {
            if (opt & SGT_RANGE_DOWN_INCLUDED) {
                if (value >= range.range_down) {
                    ;
                } else {
                    return sgt_error_assign(str, LOWER_BOUND_REACHED);
                }
            } else {
                return sgt_error_assign(str, LOWER_BOUND_REACHED);
            }
        }
    }
    if (opt & SGT_MODULO) {
        if (fmod(value, range.modulo) == 0) {
            ;
        } else {
            return sgt_error_assign(str, MODULO_MISSMATCH);
        }
    }
}

void sgt_init(void)
{
    error_messages[MULTIPLE_FLOATING_POINTS] = "MULTIPLE_FLOATING_POINTS";
    error_messages[INVALID_WHITESPACE] = "INVALID_WHITESPACE";
    error_messages[MULTIPLE_MINUSES] = "MULTIPLE_MINUSES";
    error_messages[MULTIPLE_PLUSES] = "MULTIPLE_PLUSES";
    error_messages[FLYING_MINUS] = "FLYING_MINUS";
    error_messages[FLYING_PLUS] = "FLYING_PLUS";
    error_messages[NEGATIVE_NUMBER] = "NEGATIVE_NUMBER";
    error_messages[DECIMAL_NUMBER] = "DECIMAL_NUMBER";
    error_messages[UPPER_BOUND_REACHED] = "UPPER_BOUND_REACHED";
    error_messages[LOWER_BOUND_REACHED] = "LOWER_BOUND_REACHED";
    error_messages[POSITIVE_NUMBER] = "POSITIVE_NUMBER";
    error_messages[INCOMPATIBLE_INSTRUCTION] = "INCOMPATIBLE_INSTRUCTION";
    error_messages[NULL_VALUE] = "NULL_VALUE";
    error_messages[INVALID_RANGE] = "INVALID_RANGE";
    error_messages[MODULO_MISSMATCH] = "MODULO_MISSMATCH";
}

int main(int argc, char **argv)
{
    sgt_init();
    customNumber_t param;
    initCustomNumber(&param);
    param.range_down = 3.0;
    param.modulo = 4.0;
    param.range_up = 7.0;
    CHECK_NUM(argv[1], SGT_ALLOW_DECIMAL | SGT_MODULO, param);
    THROW_ERR();
    return 0;   
}