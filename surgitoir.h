/*
** EPITECH PROJECT, 2018
** lskjf
** File description:
** sldkfjs$
*/

#ifndef SURGITOIR_H_
	#define SURGITOIR_H_

#include <stdlib.h>

typedef struct {
    char *token;
    int code;
} error_t;

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
    XXX_ERROR_CODE_COUNT,
} error_codes_t;

#define ERRORCOUNT XXX_ERROR_CODE_COUNT

static const char *error_messages[ERRORCOUNT];

error_t *sgt_err = NULL;
int exit_code = 84;

typedef struct {
    double range_down;
    double range_up;

    double modulo;
} customNumber_t;

customNumber_t defaultNumber = {
    0.0,
    1.0,
    1.0,
};

void initCustomNumber(customNumber_t *st)
{
    st->range_down = 0.0;
    st->range_up = 1.0;
    st->modulo = 1.0;
}

#define THROW_ERR(...) throw_err((TRUE, ##__VA_ARGS__))
#define CHECK_NUM(a, b, ...) check_number(a, b, (defaultNumber, ##__VA_ARGS__))

typedef enum {
    TRUE = 1,
    FALSE = 0,
} bool_t;

typedef enum {
    SGT_NUMBER,
    SGT_STRING,
    SGT_PATH,
} types_t;

typedef enum {
    SGT_NONE = 1,
    SGT_ALLOW_NEGATIVE = 2,
    SGT_STRICT_NEGATIVE = 4,
    SGT_ALLOW_DECIMAL = 8,
    SGT_NON_NULL = 16,
    SGT_RANGE_UP_INCLUDED = 32,
    SGT_RANGE_DOWN_INCLUDED = 64,
    SGT_RANGE = 128,
    SGT_MODULO = 256,
}  number_opts_t;

typedef struct {
    char *value;
    int ridx;
} arg_t;

typedef struct {
    int idx;
    char *arg;

    bool_t longopt;
    arg_t * args;
    
} param_t;


#endif /* !SURGITOIR_H_ */
