/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** free.c
*/

#include "my_malloc.h"

void free(void *ptr)
{
    list_t *head = NULL;

    if (ptr == NULL)
        return;
    head = (list_t *)ptr - sizeof(list_t);
    head->is_free = true;
}