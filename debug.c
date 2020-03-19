/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** debug.c
*/
#include <main.h>
#include <debug.h>

void my_debug(controls_t *controls, uchar_t no_next, uchar_t level,
    vec_t *size)
{
    my_putstr("*** DEBUG MODE ***\n\rKey Left :  ");
    key_printer(controls->key_left);
    my_putstr("\n\rKey Right :  ");
    key_printer(controls->key_right);
    my_putstr("\n\rKey Turn :  ");
    key_printer(controls->key_turn);
    my_putstr("\n\rKey Drop :  ");
    key_printer(controls->key_drop);
    my_putstr("\n\rKey Quit :  ");
    key_printer(controls->key_quit);
    my_putstr("\n\rKey Pause :  ");
    key_printer(controls->key_pause);
    my_putstr("\n\rNext :  ");
    my_putstr(no_next ? "No\n\rLevel :  " : "Yes\n\rLevel :  ");
    my_putnbr(level);
    my_putstr("\n\rSize :  ");
    my_putnbr(size->y);
    my_putchar('*');
    my_putnbr(size->x);
    my_putstr("\n\rTetriminos :  ");
}
