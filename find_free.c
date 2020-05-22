/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include <stddef.h>
#include "malloc.h"

static const long int PAGESIZE = 4096;

static size_t find_contiguous(minfo_t cur, size_t s)
{
    size_t acc = 0;
    const ptrdiff_t t = cur->n - cur;

    if (cur->free && t > 0 && (size_t)t >= s)
        return cur->n - cur;
    for (minfo_t next = cur; MEM(next) < sbrk(0)
            && next->free && acc < s; next = next->n)
        acc += next->n ? next->n - next : 0;
    return acc;
}

void *find_free(size_t s)
{
    static minfo_t hs = NULL;
    size_t bestfit = 0;
    size_t tmp = 0;
    void *r = NULL;

    for (minfo_t cur = hs; cur; cur = cur->n) {
        tmp = find_contiguous(cur, s);
        if (tmp < bestfit) {
            bestfit = tmp;
            r = cur;
        }
    }
    r = r && MEM(r) < sbrk(0) ? r : append_mem(hs, s);
    ((minfo_t)r)->pointed = MEM(r);
    ((minfo_t)r)->free = 0;
    ((minfo_t)r)->size = s;
    return MEM(r);
}

static bool expandbrk(intptr_t i)
{
    size_t cur = (size_t)sbrk(0);
    const long pagesize = (sysconf(_SC_PAGESIZE) ? sysconf(_SC_PAGESIZE)
            : PAGESIZE) * 2;

    i += (cur % pagesize) ? pagesize - cur % pagesize : 0;
    i += (i % pagesize) ? pagesize - i % pagesize : 0;
    return (sbrk(i) == (void *)-1);
}

void *append_mem(minfo_t hs, size_t s)
{
    minfo_t newtop = sbrk(0);
    minfo_t tmp = hs;

    if (expandbrk(LSMI + s))
        return NULL;
    newtop->n = NULL;
    for (; tmp; tmp = tmp->n);
    if (tmp)
        tmp->n = newtop;
    else
        tmp = newtop;
    return newtop;
}
