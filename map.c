/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "../include/my.h"

void display_map(void)
{
    int x = 10;
    int y = 20;

    mvprintw(1, 33, "+");
    mvprintw(1, 33 + x * 2 + 2, "+");
    mvprintw(2 + y, 33, "+");
    mvprintw(2 + y, 33 + x * 2 + 2, "+");
    for (int i = 1; i <= x * 2 + 1; i++) {
        mvprintw(1, 33 + i, "-");
        mvprintw(2 + y, 33 + i, "-");
    }
    for (int i = 1; i < y + 1; i++) {
        mvprintw(1 + i, 33, "|");
        mvprintw(1 + i, 33 + x * 2 + 2, "|");
    }
}

void display_scor_borad(void)
{
    int x = 11;
    int y = 8;

    mvprintw(8, 1, "/");
    mvprintw(8, 1 + x * 2 + 2, "\\");
    mvprintw(9 + y, 1, "\\");
    mvprintw(9 + y, 1 + x * 2 + 2, "/");
    for (int i = 1; i <= x * 2 + 1; i++) {
        mvprintw(8, 1 + i, "-");
        mvprintw(9 + y, 1 + i, "-");
    }
    for (int i = 1; i < y + 1; i++) {
        mvprintw(8 + i, 1, "|");
        mvprintw(8 + i, 1 + x * 2 + 2, "|");
    }
}
