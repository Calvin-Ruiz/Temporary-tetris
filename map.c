/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** map.c
*/
#include <curses.h>

void display_map(void)
{
    int x = 10;
    int y = 20;

    mvaddch(1, 33, '+');
    mvaddch(1, 33 + x * 2 + 2, '+');
    mvaddch(2 + y, 33, '+');
    mvaddch(2 + y, 33 + x * 2 + 2, '+');
    for (int i = 1; i <= x * 2 + 1; i++) {
        mvaddch(1, 33 + i, '-');
        mvaddch(2 + y, 33 + i, '-');
    }
    for (int i = 1; i < y + 1; i++) {
        mvaddch(1 + i, 33, '|');
        mvaddch(1 + i, 33 + x * 2 + 2, '|');
    }
}

void display_scoreboard(void)
{
    int x = 11;
    int y = 8;

    mvaddch(8, 1, '/');
    mvaddch(8, 1 + x * 2 + 2, '\\');
    mvaddch(9 + y, 1, '\\');
    mvaddch(9 + y, 1 + x * 2 + 2, '/');
    mvaddchstr(8, 11, (const chtype *) "Hight Score");
    mvaddchstr(9, 11, (const chtype *) "Score");
    mvaddchstr(11, 11, (const chtype *) "Lines");
    mvaddchstr(12, 11, (const chtype *) "Level");
    mvaddchstr(13, 11, (const chtype *) "Timer");
    for (int i = 1; i <= x * 2 + 1; i++) {
        mvaddch(8, 1 + i, '-');
        mvaddch(9 + y, 1 + i, '-');
    }
    for (int i = 1; i < y + 1; i++) {
        mvaddch(8 + i, 1, '|');
        mvaddch(8 + i, 1 + x * 2 + 2, '|');
    }
}
