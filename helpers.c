/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include <string.h>
#include "malloc.h"

void *ptrcpy(void *o, void *n)
{
    if (!n)
        return n;
    memmove(n, o, MIN(IMPL(n)->size, IMPL(o)->size) + LSMI);
    free(o);
    return n;
}
