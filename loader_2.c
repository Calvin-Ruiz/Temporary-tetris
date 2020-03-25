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
    char *display = (char *) piece->display[0];
    short y = -1;

    write(1, " : Size ", 8);
    my_putnbr(piece->size.x);
    write(1, "*", 1);
    my_putnbr(piece->size.y);
    write(1, " :  Color ", 10);
    my_putnbr(piece->color);
    write(1, " :\n", 3);
    while (++y < piece->size.y) {
        write(1, display, piece->size.x);
        write(1, "\n", 1);
        display += piece->size.x;
    }
}

void my_list_up(loader_t **ptmp, loader_t **ptmp_old)
{
    loader_t *tmp_next;
    loader_t *tmp;
    loader_t *tmp_old;

    tmp = *ptmp;
    tmp_old = *ptmp_old;
    tmp_next = tmp->next;
    if (my_strcmp(tmp->name, tmp_next->name) > 0) {
        tmp->next = tmp_next->next;
        tmp_old->next = tmp_next;
        tmp_next->next = tmp;
    }
    *ptmp_old = tmp_old->next;
    *ptmp = tmp_old->next->next;
}

void my_sort_list(loader_t **my_list, int len)
{
    loader_t *tmp;
    loader_t *tmp_old;
    loader_t *linker;

    linker = my_malloc(sizeof(**my_list));
    linker->name = "";
    linker->next = *my_list;
    while (--len > 0) {
        tmp = linker->next;
        tmp_old = linker;
        while (tmp->next != NULL)
            my_list_up(&tmp, &tmp_old);
    }
    *my_list = linker->next;
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
