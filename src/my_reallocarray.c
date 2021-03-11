/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** my_reallocarray.c
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    list_t *f_elem = NULL;
    void *memo = NULL;

    if (ptr == NULL)
        return malloc(size);
    if (nmemb <= 0 && size <= 0 && ptr)
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