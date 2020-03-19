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

char *create_rotated_piece(char *piece_array, vec_t *size);
void append_piece_from_file(char *filename, dict_t **loader);
piece_t **build_piece_array(loader_t *loader, uchar_t *nb_valid_pieces);
void debug_display(loader_t *loader);
piece_t **load_piece_array(char is_debug, uchar_t *nb_valid_pieces);

#endif /* LOADER_H_ */
