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
    my_sort_list(&loader);
    while (loader != NULL) {
        write(1, "Tetriminos : ",13);
        my_putstr_del(loader->name);
        if (loader->piece)
            my_prompt_piece_datas(loader->piece);
        else
            write(1, ":  Error\n\r", 10);
        my_list = my_list->next;
    }
}

static piece_t *builder_tetrimino(piece_t *piece, char **arr, long len)
{
    char *end = arr[0] + len;
    char *beg = arr[1] - 1;
    uchar_t *tmp;
    if (piece == NULL || (long) arr[-1] <= piece->size.y)
        return (NULL);
    while (++beg < end) {
        if (*beg != ' ' && *beg != '*' && *beg != '\0')
            return (NULL);
    }
    tmp = spacefilled_malloc(piece->size.x * piece->size.y);
    *piece->display = tmp;
    for (uchar_t i = 0; i++ < piece->size.y;) {
        fast_strncpy(tmp, arr[i], piece->size.x);
        tmp += piece->size.x;
    }
    piece->display[1] = create_rotated_piece(*piece->display, &piece->size);
    piece->display[2] = create_rotated_piece(piece->display[1],
        &((vec_t) {piece->size.y, piece->size.x}));
    piece->display[3] = create_rotated_piece(piece->display[2], &piece->size);
    return (piece);
}

static piece_t *parser_tetrimino(piece_t *piece, char *line)
{
    char **tab;

    if (line == NULL)
        return (NULL);
    tab = line_to_arr(line, ' ');
    if (tab == NULL || (long) tab[-1] != 3)
        return (NULL);
    piece->size.x = my_getnbr(tab[0]);
    piece->size.y = my_getnbr(tab[1]);
    piece->color = my_getnbr(tab[2]);
    piece->dir = 0;
    piece->pos.y = 0;
    free(tab - 1);
    return (piece);
}

void append_piece_from_file(char *filename, dict_t **loader)
{
    piece_t *piece = malloc(sizeof(piece_t));
    int fd = open(tmpcat("tetriminos/", filename), O_RDONLY);
    long len = 0;
    char *str = my_read(fd, &len);
    char **arr = line_to_arr(str, '\n');

    if (piece == NULL || arr == NULL || (long) arr[-1] < 2) {
        append_to_dict(loader, filename, NULL);
        return;
    }
    close(fd);
    piece = parser_tetrimino(piece, str);
    piece = builder_tetrimino(piece, arr, len);
    free(str);
    free(arr - 1);
    append_to_dict(loader, filename, piece);
}

piece_t **load_piece_array(char is_debug, uchar_t *nb_valid_pieces)
{
    dict_t *loader = NULL;
    DIR *dir = opendir("tetriminos");
    struct dirent *my_dirent = readdir(dir);
    piece_t **pieces;

    while (my_dirent) {
        if (*my_dirent->d_name == '.') {
            my_dirent = readdir(dir);
            continue;
        }
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
