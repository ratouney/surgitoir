/*
** EPITECH PROJECT, 2018
** slkfjsd
** File description:
** sdklfjsd
*/

#include <stdlib.h>
#include "surgitoir.h"

static bool_t check_range_up(char *str, number_opts_t opt, customNumber_t *param, double value)
{
    if (value >= param->range_up) {
        if (opt & SGT_RANGE_UP_INCLUDED) {
            if (value > param->range_up) {
                return sgt_error_assign(str, UPPER_BOUND_REACHED);
            }
        } else {
            return sgt_error_assign(str, UPPER_BOUND_REACHED);
        }
    }
    return SGT_TRUE;
}

static bool_t check_range_down(char *str, number_opts_t opt, customNumber_t *param, double value)
{
    if (value <= param->range_down) {
        if (opt & SGT_RANGE_DOWN_INCLUDED) {
            if (value < param->range_down) {
                return sgt_error_assign(str, LOWER_BOUND_REACHED);
            }
        } else {
            return sgt_error_assign(str, LOWER_BOUND_REACHED);
        }
    }
    return SGT_TRUE;
}

bool_t check_range(char *str, number_opts_t opt, customNumber_t *param, double value)
{
    if (opt & SGT_RANGE) {
        ;
    } else {
        return SGT_TRUE;
    }
    if (param == NULL)
        return sgt_error_assign(str, NO_PARAMS_PROVIDED);
    if (param->range_up < param->range_down) {
        return sgt_error_assign(str, INVALID_RANGE);
    }
    if (check_range_down(str, opt, param, value) == SGT_FALSE)
        return SGT_FALSE;
    if (check_range_up(str, opt, param, value) == SGT_FALSE)
        return SGT_FALSE;
    return SGT_TRUE;
}