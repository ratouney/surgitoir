/*
** EPITECH PROJECT, 2018
** lksjdf
** File description:
** sldkfj
*/

#include <string.h>
#include <stdio.h>
#include "surgitoir.h"

bool_t sgt_error_assign(char *token, int code)
{
    if (sgt_err == NULL)
        if ((sgt_err = malloc(sizeof(error_t))) == NULL)
            exit(69);
    if (sgt_err->token != NULL)
        free(sgt_err->token);
    sgt_err->token = strdup(token);
    sgt_err->code = code;
    return FALSE;
}

void throw_err(bool_t crash)
{
    if (sgt_err == NULL)
        return;
    dprintf(2, "[%s] --> %s\n", sgt_err->token, error_messages[sgt_err->code]);
    if (crash == TRUE)
        exit(exit_code);
}

void set_exit_code(int code)
{
    exit_code = code;
}