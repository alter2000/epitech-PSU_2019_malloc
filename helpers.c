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
    n = memcpy(o, n, MIN(((minfo_t)(n - LSMI))->size + LSMI,
                        ((minfo_t)(o - LSMI))->size) + LSMI);
    ((minfo_t)(n - LSMI))->size = ((minfo_t)(o - LSMI))->size;
    free(o);
    return n;
}
