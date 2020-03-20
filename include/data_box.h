/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** data_box.h
*/

#ifndef DATA_BOX_H_
#define DATA_BOX_H_

typedef struct data_box {
    vec_t pos;
    ushort_t high_score;
    ushort_t score;
    ushort_t nb_lines;
    uchar_t level;
    clock_t time;
} data_box_t;

static inline void my_putter(ushort_t data, ushort x, ushort y)
{
    if (data >= 1000)
        mvaddch(y, x - 3, '0' + data / 1000);
    if (data >= 100)
        mvaddch(y, x - 2, '0' + (data / 100) % 10);
    if (data >= 10)
        mvaddch(y, x - 1, '0' + (data / 10) % 10);
    mvaddch(y, x, '0' + data % 10);
}

static inline void draw_datas(data_box_t *datas)
{
    my_putter(datas->high_score, datas->pos.x, datas->pos.y);
    my_putter(datas->score, datas->pos.x, datas->pos.y + 1);
    my_putter(datas->nb_lines, datas->pos.x, datas->pos.y + 3);
    my_putter(datas->level, datas->pos.x, datas->pos.y + 4);
    my_putter(datas->time / 60, datas->pos.x - 3, datas->pos.y + 6);
    addch(':');
    addch('0' + (datas->time / 10) % 6);
    addch('0' + datas->time % 10);
}

static inline data_box_t *create_data_box(void)
{
    static data_box_t data;

    data = (data_box_t) {(vec_t) {23, 10}, 0, 0, 0, 1, 0};
    return (&data);
}

#endif /* DATA_BOX_H_ */
