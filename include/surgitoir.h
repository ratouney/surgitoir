/*
** EPITECH PROJECT, 2018
** lskjf
** File description:
** sldkfjs$
*/

#ifndef SURGITOIR_H_
	#define SURGITOIR_H_

#include "surgitoir-number.h"
#include "surgitoir-error.h"
#include "surgitoir-globals.h"
#include "surgitoir-enums.h"
#include "surgitoir-bool.h"

typedef enum {
    SGT_NUMBER,
    SGT_STRING,
    SGT_PATH,
} types_t;

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

bool_t sgt_error_assign(char *, int);
bool_t is_in(char *haystack, char needle);
bool_t is_num(char *str);
void initCustomNumber(customNumber_t *st);
void throw_err(bool_t crash);
bool_t check_number(char *str, number_opts_t opt, customNumber_t *range);

#endif /* !SURGITOIR_H_ */
