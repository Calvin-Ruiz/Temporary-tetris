/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** option.h
*/

#ifndef OPTION_H_
#define OPTION_H_

#include <time.h>
#include <curses.h>
#include <main.h>

typedef struct option_catcher {
    dict_t *single;
    dict_t *basics;
    dict_t *bools;
    char *level;
    char *size;
} option_t;

option_t *init_option_catcher(controls_t *controls, param_t *params);
void catch_options_and_destroy(option_t *option, char **av);

#endif /* OPTION_H_ */
