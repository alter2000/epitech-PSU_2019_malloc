/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include <errno.h>
#include "malloc.h"

static const size_t PAGESIZE = 4096;

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
    size_t m = n * s;

    if (m < n || m < s) {
        errno = ENOMEM;
        return NULL;
    }
    p = malloc(m);
    for (size_t i = 0; i < m; i++)
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
    if (p == new)
        return new;
    return mymemcpy(p, new, n);
}

void *reallocarray(void *p, size_t n, size_t s)
{
    if (n * s < n || n * s < s) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(p, n * s);
}
