/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include "malloc.h"

static bool prev_alloc(void *p)
{
    return (p < sbrk(0) && ((minfo_t)p - LSMI)->free == 0);
}

void free(void *p)
{
    if (prev_alloc(p) && (size_t)p % 2 == 0)
        ((minfo_t)p - LSMI)->free = true;
}
