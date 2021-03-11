/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** my_malloc.h
*/

#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef struct list_s
{
    size_t size;
    bool is_free;
    struct list_s *next;
} list_t;

list_t *f_elem;
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif