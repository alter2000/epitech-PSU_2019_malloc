/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include "malloc.h"

static const size_t PAGESIZE = 4096;

static size_t find_contiguous(minfo_t cur, size_t s)
{
    size_t acc = 0;

    if (cur->free && cur->n - cur >= s)
        return cur->n - cur;
    for (minfo_t next = cur; next->free; next = next->n) {
        if (next->n)
            acc += next->n - next;
        if (acc >= s)
            break;
    }
    return acc;
}

void *find_free(size_t s)
{
    static minfo_t hs = NULL;
    size_t bestfit = 0;
    size_t tmp = 0;
    void *r = NULL;

    if (!s)
        return NULL;
    for (minfo_t cur = hs; cur; cur = cur->n) {
        tmp = find_contiguous(cur, s);
        if (tmp < bestfit) {
            bestfit = tmp;
            r = cur;
        }
    }
    return (r) ? r + LSMI : append_mem(hs, s);
}

static bool expandbrk(intptr_t i)
{
    void *cur = sbrk(0);
    long pagesize = sysconf(_SC_PAGESIZE);

    if (!pagesize)
        pagesize = PAGESIZE;
    i += (i % pagesize) ? i % pagesize : 0;
    i += ((size_t)cur % pagesize) ? (size_t)cur % pagesize : 0;
    return (sbrk(i) == (void *)-1);
}

void *append_mem(minfo_t hs, size_t s)
{
    minfo_t newtop = sbrk(0);
    minfo_t tmp = hs;

    if (expandbrk(LSMI + s))
        return NULL;
    newtop->free = true;
    newtop->n = NULL;
    for (; tmp; tmp = tmp->n);
    if (tmp)
        tmp->n = newtop;
    else
        tmp = newtop;
    return newtop + LSMI;
}

void split(minfo_t b, size_t len)
{
    minfo_t new = (minfo_t)(
                        (unsigned char *)b
                        + len
                        + sizeof(b)
                        - 1);
    new->n = b->n;
    new->free = true;
    b->n = new;
}
