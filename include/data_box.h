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

static inline data_box_t *create_data_box(void)
{
    static data_box_t data;

    return (&data);
}

#endif /* DATA_BOX_H_ */
