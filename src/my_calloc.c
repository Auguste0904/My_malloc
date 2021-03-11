/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** my_calloc.c
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *handle = NULL;
    size_t malloc_size = 0;

    if (nmemb <= 0 || size <= 0)
        return (NULL);
    malloc_size = nmemb * size;
    handle = malloc(malloc_size);
    if (handle == NULL)
        return (NULL);
    memset(handle, 0, malloc_size);
    return (handle);
}