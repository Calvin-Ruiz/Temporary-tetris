/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include <signal.h>
#include <main.h>
#include <map.h>
#include <tools.h>
#include <my_read.h>
#include "dict.h"
#include "option.h"

void my_event(void)
{
    return;
}

void display_help(void)
{
    int fd = open("readme.txt", O_RDONLY);
    char *str;
    long int len = 0;

    if (fd == -1)
        exit(84);
    str = my_read(fd, &len);
    if (str == NULL)
        exit(84);
    write(1, str, len);
    exit(0);
}

static void my_init(void)
{
    keypad(stdscr, TRUE);
    initscr();
    nonl();
    cbreak();
    echo();
    timeout(0);
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }
    erase();
    display_map();
    display_scoreboard();
    diplsay_tetris();
}

void mainloop(controls_t *controls)
{
    my_putchar(27);
    my_putchar('c');
}

int main(int ac, char **av)
{
    controls_t controls = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 'q', ' '};
    game_t game;
    param_t params = {0, 0, 0};
    option_t *option = init_option_catcher(&controls, &params);

    my_init();
    refresh();
    read(0, 0, 1);
    mainloop(&controls);
    endwin();
    return (0);
}
