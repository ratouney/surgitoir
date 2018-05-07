/*
** EPITECH PROJECT, 2018
** lskdjf
** File description:
** lskdjf
*/

#ifndef ENUMS_H_
	#define ENUMS_H_

typedef enum {
    MULTIPLE_FLOATING_POINTS,
    INVALID_WHITESPACE,
    MULTIPLE_MINUSES,
    MULTIPLE_PLUSES,
    FLYING_MINUS,
    FLYING_PLUS,
    NEGATIVE_NUMBER,
    DECIMAL_NUMBER,
    UPPER_BOUND_REACHED,
    LOWER_BOUND_REACHED,
    POSITIVE_NUMBER,
    INCOMPATIBLE_INSTRUCTION,
    NULL_VALUE,
    INVALID_RANGE,
    MODULO_MISSMATCH,
    NO_PARAMS_PROVIDED,
    IS_NAN,
    STRTOD_FAILED,
    XXX_ERROR_CODE_COUNT,
} error_codes_t;

#define ERRORCOUNT XXX_ERROR_CODE_COUNT

#endif /* !ENUMS_H_ */
