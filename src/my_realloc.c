/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** my_realloc.c
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    list_t *f_elem = NULL;
    void *memo = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (size <= 0 && ptr != NULL)
        free(ptr);
    f_elem = (list_t *)ptr - sizeof(list_t);
    if (f_elem->size >= size)
        return (ptr);
    memo = malloc(size);
    if (memo != NULL) {
        memcpy(memo, ptr, f_elem->size);
        free(ptr);
    }
    return (memo);
}