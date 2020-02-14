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

    if (!p)
        return malloc(n);
    if (!n) {
        free(p);
        return NULL;
    }
    new = find_free(n);
    return (p == new) ? new : mymemcpy(p, new, n);
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
