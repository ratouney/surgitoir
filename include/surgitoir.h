/*
** EPITECH PROJECT, 2018
** lskjf
** File description:
** sldkfjs$
*/

#ifndef SURGITOIR_H_
	#define SURGITOIR_H_

#include "number.h"
#include "error.h"
#include "globals.h"
#include "enums.h"

typedef enum {
    TRUE = 1,
    FALSE = 0,
} bool_t;

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


#endif /* !SURGITOIR_H_ */
