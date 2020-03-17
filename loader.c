/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** loader.c
*/

#include <piece.h>
#include <loader.h>
#include <dirent.h>

piece_t *parser_tetrimino(int fd, piece_t *piece)
{
    char *line = get_next_line(fd);
    char **tab;
    if (line == NULL)
        return (NULL);
    piece->size.x;
    if () {
        piece->size.y;
        piece->color;
    } else
        return (NULL);
    return (piece);
}

void append_piece_from_file(const char *filename, dict_t **loader)
{
    piece_t *piece = malloc(sizeof(piece_t));
    int fd = open(filename, O_RDONLY);

    if (piece == NULL || fd == -1)
        return;
    piece = parser_tetrimino(fd, piece);
    if (piece == NULL)
        return;
    close(fd);
    append_to_dict(loader, filename, piece);
}

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
