/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <signal.h>
#include <main.h>

static void my_init_ncurses(void)
{
    keypad(stdscr, TRUE);
    initscr();
    nonl();
    cbreak();
    echo();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int main(int ac, char **av)
{
    controls_t controls = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 'q', ' '};

    my_init_ncurses();
    endwin();
    return (0);
}
