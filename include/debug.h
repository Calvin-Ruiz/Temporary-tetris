/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.h
*/

#ifndef DEBUG_H_
#define DEBUG_H_

#include <tools.h>

static inline void key_printer(chtype c)
{
    if (c >= 256)
        key_printer(c >> 8);
    my_putchar(c & 255);
}

void my_debug(controls_t *controls, uchar_t no_next, uchar_t level,
    vec_t *size);

#endif /* DEBUG_H_ */
