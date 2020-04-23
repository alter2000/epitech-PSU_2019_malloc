/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include <errno.h>
#include "malloc.h"

void *malloc(size_t s)
{
    if (!s) {
        errno = ENOMEM;
        return NULL;
    }
    if (s % 2)
        ++s;
    return find_free(s);
}

void *calloc(size_t n, size_t s)
{
    unsigned char *p = NULL;
    size_t mul = n * s;

    if (mul < n || mul < s) {
        errno = ENOMEM;
        return NULL;
    }
    p = malloc(mul);
    if (!p)
        return p;
    for (size_t i = 0; i < mul; i++)
        p[i] = 0;
    return p;
}

void *realloc(void *p, size_t n)
{
    void *new;

    if (!n) {
        free(p);
        return NULL;
    } else if (!p)
        return malloc(n);
    if (!proper_alloc(p)) {
        write(STDERR_FILENO, "realloc: invalid pointer\n", 25);
        _exit(84);
    }
    new = find_free(n);
    return (p == new) ? new : ptrcpy(p, new);
}

void *reallocarray(void *p, size_t n, size_t s)
{
    size_t mul = n * s;

    if (mul < n || mul < s) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(p, mul);
}
