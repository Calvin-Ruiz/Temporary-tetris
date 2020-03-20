/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** loader.c
*/

#include <piece.h>
#include <loader.h>
#include <dirent.h>
#include <fcntl.h>
#include <my_getnbr.h>
#include <my_read.h>

void debug_display(loader_t *loader)
{
    return;
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

static piece_t *parser_tetrimino(int fd, piece_t *piece, char *line)
{
    char **tab;

    if (line == NULL)
        return (NULL);
    tab = line_to_arr(line, ' ');
    if ((long) tab[-1] != 3)
        return (NULL);
    piece->size.x = my_getnbr(tab[0]);
    if (tab[1] && tab[2]) {
        piece->size.y = my_getnbr(tab[1]);
        piece->color = my_getnbr(tab[2]);
    } else
        return (NULL);
    return (piece);
}

void append_piece_from_file(char *filename, dict_t **loader)
{
    piece_t *piece = malloc(sizeof(piece_t));
    int fd = open(tmpcat("tetriminos/", filename), O_RDONLY);
    long len = 0;
    char *str = my_read(fd, &len);
    char **arr = line_to_arr(str, '\n');

    if (piece == NULL || arr == NULL) {
        append_to_dict(loader, filename, NULL);
        return;
    }
    piece = parser_tetrimino(fd, piece, str);
    if (piece == NULL) {
        append_to_dict(loader, filename, NULL);
        return;
    }
    close(fd);
    append_to_dict(loader, filename, piece);
}

piece_t **load_piece_array(char is_debug, uchar_t *nb_valid_pieces)
{
    dict_t *loader = NULL;
    DIR *dir = opendir("tetriminos");
    struct dirent *my_dirent = readdir(dir);
    piece_t **pieces;

    while (my_dirent) {
        append_piece_from_file(my_dirent->d_name, &loader);
        my_dirent = readdir(dir);
    }
    closedir(dir);
    if (is_debug)
        debug_display((loader_t *) loader);
    pieces = build_piece_array((loader_t *) loader, nb_valid_pieces);
    destroy_dict(loader, NULL);
    return (pieces);
}
