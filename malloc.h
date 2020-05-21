/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#ifndef LIBMINE_MALLOC_H_
# define LIBMINE_MALLOC_H_

# include <unistd.h>
# include <stdbool.h>

typedef struct sminfo *minfo_t;
struct sminfo {
    struct sminfo *n;
    size_t size;
    void *pointed;
    int free;
};

# define LSMI sizeof(struct sminfo)
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

void *malloc(size_t s);
void *realloc(void *p, size_t n);
void *calloc(size_t n, size_t s);
void *reallocarray(void *p, size_t n, size_t s);
void free(void *p);

void *find_free(size_t s);
void *append_mem(minfo_t hs, size_t s);
bool proper_alloc(void *p);

void *ptrcpy(void *o, void *n);

#endif
