/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** data_box.h
*/

#ifndef DATA_BOX_H_
#define DATA_BOX_H_

#include <fcntl.h>

typedef struct data_box {
    vec_t pos;
    uint_t high_score;
    uint_t score;
    ushort_t nb_lines;
    uchar_t level;
    clock_t time;
} data_box_t;

static inline void my_putter(uint_t data, ushort x, ushort y)
{
    if (data == 0)
        mvaddch(y, x, '0');
    while (data) {
        mvaddch(y, x--, '0' + data % 10);
        data /= 10;
    }
}

static inline void draw_datas(data_box_t *datas)
{
    const clock_t t = datas->time / CLOCKS_PER_SEC;

    my_putter(datas->high_score, datas->pos.x, datas->pos.y);
    my_putter(datas->score, datas->pos.x, datas->pos.y + 1);
    my_putter(datas->nb_lines, datas->pos.x, datas->pos.y + 3);
    my_putter(datas->level, datas->pos.x, datas->pos.y + 4);
    my_putter(t / 60, datas->pos.x - 3, datas->pos.y + 6);
    mvaddch(datas->pos.y + 6, datas->pos.x - 2, ':');
    addch('0' + (t / 10) % 6);
    addch('0' + t % 10);
}

static inline data_box_t *create_data_box(void)
{
    static data_box_t data;

    data = (data_box_t) {(vec_t) {23, 10}, 0, 0, 0, 1, 0};
    return (&data);
}

static inline void export_score(data_box_t *datas)
{
    int fd;

    if (datas->score <= datas->high_score)
        return;
    fd = open("save.dat", O_CREAT | O_WRONLY, 0666);
    if (fd == -1)
        return;
    write(fd, (char *) &datas->score, 4);
    close(fd);
}

static inline void import_score(data_box_t *datas)
{
    int fd = open("save.dat", O_RDONLY);

    if (fd == -1)
        return;
    read(fd, (char *) &datas->high_score, 4);
    close(fd);
}

#endif /* DATA_BOX_H_ */
