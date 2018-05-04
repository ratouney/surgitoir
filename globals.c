/*
** EPITECH PROJECT, 2018
** lskdjf
** File description:
** sldkfj
*/

#include "surgitoir.h"

error_t *sgt_err = NULL;

int exit_code = 84;

customNumber_t defaultNumber = {
    0.0,
    1.0,
    1.0,
};

char *error_messages[ERRORCOUNT] = {
    "MULTIPLE_FLOATING_POINTS",
    "INVALID_WHITESPACE",
    "MULTIPLE_MINUSES",
    "MULTIPLE_PLUSES",
    "FLYING_MINUS",
    "FLYING_PLUS",
    "NEGATIVE_NUMBER",
    "DECIMAL_NUMBER",
    "UPPER_BOUND_REACHED",
    "LOWER_BOUND_REACHED",
    "POSITIVE_NUMBER",
    "INCOMPATIBLE_INSTRUCTION",
    "NULL_VALUE",
    "INVALID_RANGE",
    "MODULO_MISSMATCH",
};

