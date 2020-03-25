/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** option.h
*/

#ifndef OPTION_H_
#define OPTION_H_

#include <curses.h>
#include <main.h>
#include <data_box.h>
#include <tools.h>
#include <my_getnbr.h>

typedef struct option_catcher {
    dict_t *single;
    dict_t *basics;
    dict_t *bools;
    char *level;
    char *size;
} option_t;

static inline void apply_new_size(char *str, vec_t *size)
{
    char **arr = line_to_arr(str, ',');
    vec_t new;

    if (arr == NULL || (long) arr[-1] != 2)
        return;
    new.x = my_getnbr(arr[0]);
    new.y = my_getnbr(arr[1]);
    if (new.x < 4 || new.y < 4) {
        my_puterr("Invalid size\n");
        return;
    }
    *size = new;
}

option_t *init_option_catcher(controls_t *controls, param_t *params);
void catch_options_and_destroy(option_t *option, char **av, data_box_t *datas,
    vec_t *size);

#endif /* OPTION_H_ */
