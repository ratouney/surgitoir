/*
** EPITECH PROJECT, 2018
** lskdf
** File description:
** lsdkjf
*/

#ifndef ERROR_H_
	#define ERROR_H_

#include "surgitoir-bool.h"

typedef struct {
    char *token;
    int code;
} error_t;

#define THROW_ERR(...) throw_err((TRUE, ##__VA_ARGS__))

#endif /* !ERROR_H_ */
