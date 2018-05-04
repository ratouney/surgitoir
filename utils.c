/*
** EPITECH PROJECT, 2018
** lskdjf
** File description:
** sdfk
*/

#include "surgitoir.h"

void initCustomNumber(customNumber_t *st)
{
    st->range_down = 0.0;
    st->range_up = 1.0;
    st->modulo = 1.0;
}


bool_t is_in(char *haystack, char needle)
{
    for (int i = 0; haystack[i] ; i++)
    {
        if (haystack[i] == needle)
            return TRUE;
    }
    return FALSE;
}