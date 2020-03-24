/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** loader.h
*/

#ifndef LOADER_H_
#define LOADER_H_

#include <dict.h>

typedef struct loader {
    char *name;
    piece_t *piece;
    struct loader *next;
} loader_t;

static inline void fast_strncpy(uchar_t *dest, char *src, short n)
{
    while (n-- > 0 && *src)
        *(dest++) = *(src++);
}

static inline void my_putstr_del(char *str)
{
    short i = -1;

    while (str[++i] != '.' && str[i] != '\0');
    write(1, str, i);
}

void my_sort_list(loader_t **my_list);
void my_prompt_debug(loader_t *my_list);
uchar_t *create_rotated_piece(uchar_t *piece_array, vec_t *size);
void append_piece_from_file(char *filename, dict_t **loader);
piece_t **build_piece_array(loader_t *loader, uchar_t *nb_valid_pieces);
void debug_display(loader_t *loader);
piece_t **load_piece_array(char is_debug, uchar_t *nb_valid_pieces);

#endif /* LOADER_H_ */
