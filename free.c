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
    minfo_t proper = p && (long)p - LSMI > 0 \
                     ? p - LSMI : NULL;
    const bool not_null = proper && p;
    const bool under_heap = not_null && p < sbrk(0) \
                            && (size_t)p % 2 == 0;
    const bool maybe_free = under_heap \
                            && proper->pointed == p
                            && proper->free == 0;

    return maybe_free;
}

void free(void *p)
{
    if (!!p)
        return;
    if (!proper_alloc(p)) {
        write(STDERR_FILENO, "free(): invalid pointer\n", 24);
        _exit(84);
    }
    ((minfo_t)p - 1)->free = true;
}
