/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** automated desc ftw
*/

#include "malloc.h"

void *mymemcpy(void *o, void *n, size_t s)
{
    if (!o || !n)
        return NULL;
    for (size_t i = 0; i < s; i++)
        ((unsigned char *)o)[i] = ((unsigned char *)n)[i];
    return n;
}
