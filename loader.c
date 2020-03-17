/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** loader.c
*/

#include <piece.h>
#include <loader.h>
#include <dirent.h>

piece_t **load_piece_array(char is_debug, uchar_t *nb_valid_pieces)
{
    dict_t *loader = NULL;
    DIR *dir = opendir("tetriminos");
    struct dirent *my_dirent = readdir(dir);
    piece_t *pieces;

    while (my_dirent) {
        append_piece_from_file(my_dirent->d_name, &loader);
        my_dirent = readdir(dir);
    }
    if (is_debug)
        debug_display((loader_t *) loader);
    pieces = build_piece_array((loader_t *) loader, nb_valid_pieces);
    destroy_dict(loader, NULL);
    return (pieces);
}
