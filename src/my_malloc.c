/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** malloc.c
*/

#include "my_malloc.h"

static list_t *allocate_memory(size_t size)
{
    void *ptr = sbrk(0);
    list_t *head = NULL;
    size_t block_size = 2 * getpagesize();
    size_t total_size =
    (size / block_size + (size % block_size != 0)) * block_size;

    ptr = sbrk(total_size);
    if (ptr == (void *) - 1) {
        perror("Error: Not enough space to allocate memory !");
        return (NULL);
    }
    head = ptr;
    head->size = size;
    head->is_free = false;
    head->next = NULL;
    (f_elem == NULL) ? f_elem = head : 0;
    return (ptr);
}

static list_t *algo_find_free_memory(size_t size)
{
    list_t *tmp = f_elem;
    list_t *len;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->size >= (size + sizeof(list_t)) && tmp->is_free != false)
            (len == NULL || len > tmp) ? len = tmp : 0;
    return (tmp);
}

static size_t align_power2(size_t size)
{
    size_t tmp = 1;

    while (tmp < size)
        tmp *= 2;
    return (tmp);
}

void *malloc(size_t size)
{
    list_t *head = NULL;

    if (size <= 0)
        return (NULL);
    size = align_power2(size);
    head = algo_find_free_memory(size);
    if (head != NULL) {
        head->is_free = false;
        return ((void *)(head + sizeof(list_t)));
    }
    head = allocate_memory(size + sizeof(list_t));
    return ((void *)(head + sizeof(list_t)));
}