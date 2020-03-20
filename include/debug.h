/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.h
*/

#ifndef DEBUG_H_
#define DEBUG_H_

#include <tools.h>

static inline void specific_key_printer(chtype c)
{
    char str[4] = "^EOA";

    switch (c) {
        case KEY_LEFT:
            str[3]++;
        case KEY_RIGHT:
            str[3]++;
        case KEY_DOWN:
            str[3]++;
        case KEY_UP:
            write(1, str, 4);
            break;
        default:
            write(1, "(unreferenced)", 10);
    }
}

static inline void key_printer(chtype c)
{
    if (c >= 256) {
        specific_key_printer(c);
        return;
    }
    switch (c & 255) {
        case ' ':
            write(1, "(space)", 7);
            break;
        case 27:
            write(1, "(escape)", 8);
            break;
        case '[':
            write(1, "O", 1);
            break;
        default:
            if (c & 128)
                my_putchar('^');
            my_putchar(c & 127);
    }
}

void my_debug(controls_t *controls, uchar_t no_next, uchar_t level,
    vec_t *size);

#endif /* DEBUG_H_ */
