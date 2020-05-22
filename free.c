/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include <stddef.h>
#include "malloc.h"

bool proper_alloc(void *p)
{
    minfo_t proper = (size_t)p > LSMI \
                    ? p - LSMI : NULL;
    const bool under_heap = proper && p < sbrk(0) \
                            && (size_t)p % 2 == 0;

    return under_heap;
}

void free(void *p)
{
    if (!p)
        return;
    if (!proper_alloc(p)) {
        write(STDERR_FILENO, "free(): invalid pointer\n", 24);
        _exit(84);
    }
    IMPL(p)->free = true;
}
