/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include <game.h>
#include <signal.h>
#include <map.h>
#include <my_read.h>
#include <dict.h>
#include <option.h>
#include <time.h>

void my_event(game_t *game)
{
    controls_t *cont = game->controls;
    chtype c = getch();

    if (c == cont->key_left)
        move_piece(game->actual, game->game_zone, &((vec_t) {-1, 0}));
    if (c == cont->key_right)
        move_piece(game->actual, game->game_zone, &((vec_t) {1, 0}));
    if (c == cont->key_drop)
        my_puterr("Not implemented yet\n");
    if (c == cont->key_turn)
        rotate_piece(game->actual, game->game_zone);
    if (c == cont->key_pause)
        my_puterr("Not implemented yet\n");
    if (c == cont->key_quit)
        game->is_running = 0;
}

void display_help(void)
{
    int fd = open("readme.txt", O_RDONLY);
    char *str;
    long int len = 0;

    if (fd == -1) {
        endwin();
        exit(84);
    }
    str = my_read(fd, &len);
    if (str == NULL) {
        endwin();
        exit(84);
    }
    write(1, str, len);
    endwin();
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
}

void mainloop(game_t *game)
{
    refresh();
    read(0, 0, 1);
    while (game->is_running) {
        if (game->last < clock()) {
            game->last += game->delta_time;
            update_game(game);
        }
        my_event(game);
    }
}

int main(int ac, char **av)
{
    controls_t controls = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 'q', ' '};
    param_t params = {0, 0, 0};
    game_t *game = create_game(&controls);
    option_t *option = init_option_catcher(&controls, &params);

    my_init();
    catch_options_and_destroy(option, av + 1, game->data_box);
    if (params.help);
    if (params.debug);
    init_game_zone(game->game_zone);
    mainloop(game);
    endwin();
    return (0);
}
