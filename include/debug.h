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
    switch (c & 255) {
        case ' ':
            write(1, "(space)", 7);
            break;
        case 'A':
            write(1, "^EOA", 4);
            break;
        case 'B':
            write(1, "^EOB", 4);
            break;
        case 'C':
            write(1, "^EOC", 4);
            break;
        case 'D':
            write(1, "^EOD", 4);
            break;
        default:
            my_putchar(c & 127);
    }
}

void my_debug(controls_t *controls, uchar_t no_next, uchar_t level,
    vec_t *size);

#endif /* DEBUG_H_ */
