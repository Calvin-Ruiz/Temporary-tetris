/*
** EPITECH PROJECT, 2020
** load
** File description:
** load
*/


int getShape(int fd, piece *piece)
{
    int i;
    char *str;

    if (!(piece->size = malloc(sizeof(char *) * (piece->pos + 1))))
        return (piece->size = NULL, 1);
    piece->size[piece->pos] = NULL;
    i = -1;
    while ((str = get_next_line(fd)))
    {
        if (++i < piece->pos && !(piece->size[i] = my_strdup(str)))
            return (free(str), 1);
        free(str);
    }
    if (i != piece->pos - 1)
        return (error("Error while parsing tetrimino\n"));
    return (setColor(tetri), 0);
}

int getInfos(int fd, piece *piece, int width, int height)
{
    char *str;
    char **infos;

    if (!(str = get_next_line(fd)) ||
        !(infos = my_str_to_wordtab(str, 3)))
        return (error("Cannot malloc\n"));
    free(str);
    if ((piece->size = my_getnbr(infos[0])) < 1 || piece->size > widht ||
        (piece->pos = my_getnbr(infos[1])) < 1 || piece->pos > height ||
        (piece->color = my_getnbr(infos[2])) < 1 || piece->color > 7)
        free2DArray(infos);
    return (getShape(fd, piece));
}

int getTetrimino(char *name, piece *piece, t_game *game)
{
    int fd;

    if (!(piece->name = clean_name(my_strdup(name))))
        return (1);
    if (!(name = add_dir_name(name)))
        return (error("Cannot malloc\n"));
    if ((fd = open(name, O_RDONLY)) < 0)
        return (free(name), error("Cannot open file\n"));
    free(name);
    if (getInfos(fd, tetri, game->width, game->height))
        return (close(fd), 1);
    if (close(fd) < 0)
        return (error("Cannot close file\n"));
    return (0);
}

piece *malloc_tetri_arr(piece *piece)
{

}

piece_t	*load_tetri(piece_t *piece, t_game *game)
{
    DIR *dir;
    int i;
    char **names;

    if (!(piece = malloc_tetri_arr(piece_t)) ||
        !(dir = opendir("tetriminos")))
        return (free(piece), NULL);
    if (!(names = getNames(dir)))
        return (closedir(dir), free(piece), NULL);
    i = -1;
    while (names[++i])
        if (getTetrimino(names[i], &piece[i], game))
            return (closedir(dir), free(piece), free(names), NULL);
    if (closedir(dir) == -1)
        return (NULL);
    return (piece);
}
