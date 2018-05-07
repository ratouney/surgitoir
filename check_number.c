/*
** EPITECH PROJECT, 2018
** sod
** File description:
** sldkfj
*/

#include <math.h>
#include "surgitoir.h"

static bool_t check_modulo_decimal(char *str, number_opts_t opt, customNumber_t *param, double value)
{
    if (value != round(value)) {
        if (opt & SGT_ALLOW_DECIMAL) {
            ;
        } else {
            return sgt_error_assign(str, DECIMAL_NUMBER);
        }
    }
    if (opt & SGT_MODULO) {
        if (param == NULL)
            return sgt_error_assign(str, NO_PARAMS_PROVIDED);
        if (fmod(value, param->modulo) != 0) {
            return sgt_error_assign(str, MODULO_MISSMATCH);
        }
    }
    return TRUE;
}

static bool_t check_negative(char *str, number_opts_t opt, customNumber_t *param, double value)
{
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
    (void)param;
    return TRUE;
}

bool_t check_number(char *str, number_opts_t opt, customNumber_t *param)
{
    char *test;
    double value;

    if (is_num(str) == FALSE)
        return sgt_error_assign(str, IS_NAN);
    value = strtod(str, &test);
    if (test == str)
        return sgt_error_assign(str, STRTOD_FAILED);
    if (opt & SGT_NON_NULL) {
        if (value == 0.0)
            return sgt_error_assign(str, NULL_VALUE);
    }
    if (check_negative(str, opt, param, value) == FALSE)
        return FALSE;
    if (check_modulo_decimal(str, opt, param, value) == FALSE)
        return FALSE;
    if (check_range(str, opt, param, value) == FALSE)
        return FALSE;
    return TRUE;
}