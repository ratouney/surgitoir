/*
** EPITECH PROJECT, 2018
** lksjdf
** File description:
** sldkfj
*/

#include <string.h>
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