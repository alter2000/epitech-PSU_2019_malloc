/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include <unistd.h>
#include <errno.h>

static const size_t PAGESIZE = 4096;

void *malloc(size_t s)
{
    if (!s) {
        errno = ENOMEM;
        return NULL;
    }
    return NULL;
}

void *calloc(size_t n, size_t s)
{
    if (n * s < n || n * s < s) {
        errno = ENOMEM;
        return NULL;
    }
    return malloc(n * s);
}

void free(void *p)
{
}

void *realloc(void *p, size_t n)
{
}

void *reallocarray(void *p, size_t n, size_t s)
{
    if (n * s < n || n * s < s) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(p, n * s);
}
