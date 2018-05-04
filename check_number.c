/*
** EPITECH PROJECT, 2018
** sod
** File description:
** sldkfj
*/

#include <math.h>
#include "surgitoir.h"

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
    return TRUE;
}