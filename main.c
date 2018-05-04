/*
** EPITECH PROJECT, 2018
** lskjfs
** File description:
** sldkfjs
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "surgitoir.h"

int main(int argc, char **argv)
{
    customNumber_t param;
    initCustomNumber(&param);
    param.range_down = 3.0;
    param.modulo = 4.0;
    param.range_up = 7.0;
    CHECK_NUM(argv[1], SGT_ALLOW_DECIMAL | SGT_MODULO, param);
    THROW_ERR();
    return 0;   
}