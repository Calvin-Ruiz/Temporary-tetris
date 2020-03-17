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
void append_piece_from_file(const char *filename, dict_t **loader);
piece_t **load_piece_array(char is_debug);
piece_t **build_piece_array(loader_t * loader);
void debug_display(loader_t *loader);

#endif /* LOADER_H_ */
