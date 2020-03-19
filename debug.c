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
    my_putstr("*** DEBUG MODE ***\nKey Left :  ");
    key_printer(controls->key_left);
    my_putstr("\nKey Right :  ");
    key_printer(controls->key_right);
    my_putstr("\nKey Turn :  ");
    key_printer(controls->key_turn);
    my_putstr("\nKey Drop :  ");
    key_printer(controls->key_drop);
    my_putstr("\nKey Quit :  ");
    key_printer(controls->key_quit);
    my_putstr("\nKey Pause :  ");
    key_printer(controls->key_pause);
    my_putstr("\nNext :  ");
    my_putstr(no_next ? "No\nLevel :  " : "Yes\nLevel :  ");
    my_putnbr(level);
    my_putstr("Size :  ");
    my_putnbr(size->y);
    my_putchar('*');
    my_putnbr(size->x);
    my_putstr("\nTetriminos :  ");
}
