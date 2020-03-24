/*
** EPITECH PROJECT, 2019
** C Pool Day 11
** File description:
** my_list_size.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "piece.h"
#include "loader.h"

int my_list_size(loader_t const *begin)
{
    int i = 0;
    loader_t const *tmp;

    tmp = begin;
    while (tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
