/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** loader_2.c
*/

#include <piece.h>
#include <loader.h>
#include <dirent.h>
#include <fcntl.h>
#include <my_getnbr.h>
#include <my_read.h>
#include <tools.h>

void my_prompt_piece_datas(piece_t *piece)
{
    write(1, " : Size ", 8);
    my_putnbr(piece->size.x);
    write(1, "*", 1);
    my_putnbr(piece->size.y);
    write(1, " :  Color ",10);
    my_putnbr(piece->color);
    write(1, " :\n\r",4);
}

void my_sort_list(loader_t **my_list)
{
    loader_t *tmp = (*my_list)->next;

    while (tmp) {
        if (my_strcmp((*my_list)->name, tmp->name) > 0) {
            (*my_list)->next = tmp->next;
            tmp->next = *my_list;
            *my_list = tmp;
        }
        my_list = &((*my_list)->next);
        tmp = (*my_list)->next;
    }
}

piece_t **build_piece_array(loader_t *loader, uchar_t *nb_valid_pieces)
{
    piece_t **pieces = my_malloc(0);

    *nb_valid_pieces = 0;
    while (loader) {
        if (loader->piece) {
            pieces[(*nb_valid_pieces)++] = loader->piece;
        }
        loader = loader->next;
    }
    my_malloc(sizeof(void *) * (*nb_valid_pieces));
    return (pieces);
}

uchar_t *create_rotated_piece(uchar_t *piece_array, vec_t *size)
{
    ushort_t y = size->y;
    uchar_t *display = malloc(size->x * size->y);

    if (display == NULL)
        return (piece_array);
    while (y-- > 0) {
        for (ushort_t x = -1; ++x < size->x;)
            display[y + x * size->y] = *(piece_array++);
    }
    return (display);
}
