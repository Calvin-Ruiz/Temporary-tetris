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

    mvaddch(0, 33, '+');
    mvaddch(0, 33 + x * 2 + 2, '+');
    mvaddch(1 + y, 33, '+');
    mvaddch(1 + y, 33 + x * 2 + 2, '+');
    for (int i = 1; i <= x * 2 + 1; i++) {
        mvaddch(0, 33 + i, '-');
        mvaddch(1 + y, 33 + i, '-');
    }
    for (int i = 1; i < y + 1; i++) {
        mvaddch(0 + i, 33, '|');
        mvaddch(0 + i, 33 + x * 2 + 2, '|');
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
    mvaddstr(10, 3, "Hight Score");
    mvaddstr(11, 3, "Score");
    mvaddstr(13, 3, "Lines");
    mvaddstr(14, 3, "Level");
    mvaddstr(16, 3, "Timer");
    for (int i = 1; i <= x * 2 + 1; i++) {
        mvaddch(8, 1 + i, '-');
        mvaddch(9 + y, 1 + i, '-');
    }
    for (int i = 1; i < y + 1; i++) {
        mvaddch(8 + i, 1, '|');
        mvaddch(8 + i, 1 + x * 2 + 2, '|');
    }
}

void diplsay_tetris(void)
{
    mvaddstr(0, 0, "*************");
    mvaddstr(1, 0, " * *   * * * *");
    mvaddstr(2, 0, " * **  * * ** ****");
    mvaddstr(3, 0, " * *   * * **  *");
    mvaddstr(4, 0, " * *** * * *****");
}
