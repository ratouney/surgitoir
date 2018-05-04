/*
** EPITECH PROJECT, 2018
** lsdkf
** File description:
** sdlkfj
*/

#ifndef GLOBALS_H_
	#define GLOBALS_H_

#include <stdlib.h>

#include "error.h"
#include "number.h"
#include "enums.h"


extern error_t *sgt_err;

extern int exit_code;

extern char *error_messages[ERRORCOUNT];

extern customNumber_t defaultNumber;

#endif /* !GLOBALS_H_ */
