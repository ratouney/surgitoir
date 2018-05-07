/*
** EPITECH PROJECT, 2018
** lksdjgf
** File description:
** lskdjf
*/

#include "surgitoir-number.h"

void customNumber_from(customNumber_t *param, double from)
{
    param->range_down = from;
}

void customNumber_to(customNumber_t *param, double to)
{
    param->range_up = to;
}

void customNumber_from_to(customNumber_t *param, double from, double to)
{
    param->range_down = from;
    param->range_up = to;
}
