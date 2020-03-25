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
#include <debug.h>
#include <loader.h>

void my_event(game_t *game)
{
    controls_t *cont = game->controls;
    chtype c = getch();

    if (c == cont->key_left && !game->is_paused)
        move_piece(game->actual, game->game_zone, &((vec_t) {-1, 0}));
    if (c == cont->key_right && !game->is_paused)
        move_piece(game->actual, game->game_zone, &((vec_t) {1, 0}));
    if (c == cont->key_drop && !game->is_paused) {
        update_game(game);
        game->data_box->score++;
    }
    if (c == cont->key_turn && !game->is_paused)
        rotate_piece(game->actual, game->game_zone);
    if (c == cont->key_pause)
        game->is_paused = !game->is_paused;
    if (c == cont->key_quit)
        game->is_running = 0;
    draw_datas(game->data_box);
    if (c)
        draw_game_zone(game->game_zone, game->actual);
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
    endwin();
    write(1, str, len);
    exit(0);
}

void mainloop(game_t *game)
{
    game->actual = clone_piece(game->pieces[clock() % game->nb_pieces],
        game->game_zone->size.x >> 1);
    game->preview = clone_piece(game->pieces[clock() % game->nb_pieces],
        game->game_zone->size.x >> 1);
    game->delta_time = CLOCKS_PER_SEC / game->data_box->level;
    import_score(game->data_box);
    if (game->display_next)
        display_next(game);
    while (game->is_running) {
        if (!game->is_paused && game->last < clock()) {
            game->last = clock() + game->delta_time;
            game->data_box->time += game->delta_time;
            update_game(game);
        }
        my_event(game);
    }
    export_score(game->data_box);
}

void fixing(controls_t *controls)
{
    if (controls->key_left >= 16777216)
        controls->key_left = *((uchar_t *) controls->key_left);
    if (controls->key_right >= 16777216)
        controls->key_right = *((uchar_t *) controls->key_right);
    if (controls->key_drop >= 16777216)
        controls->key_drop = *((uchar_t *) controls->key_drop);
    if (controls->key_turn >= 16777216)
        controls->key_turn = *((uchar_t *) controls->key_turn);
    if (controls->key_quit >= 16777216)
        controls->key_quit = *((uchar_t *) controls->key_quit);
    if (controls->key_pause >= 16777216)
        controls->key_pause = *((uchar_t *) controls->key_pause);
}

int main(int ac, char **av)
{
    controls_t controls = {'D', 'C', 'A', 'B', 'q', ' '};
    param_t params = {0, 0, 0};
    game_t *game = create_game(&controls);
    option_t *option = init_option_catcher(&controls, &params);
    catch_options_and_destroy(option, av + 1, game->data_box,
        &game->game_zone->size);
    fixing(&controls);
    if (params.help)
        display_help();
    if (params.debug)
        my_debug(&controls, params.no_next, game->data_box->level,
            &game->game_zone->size);
    game->pieces = load_piece_array(params.debug, &game->nb_pieces);
    my_init();
    if (params.debug)
        read(0, *av, 1);
    init_game(game, !params.no_next);
    mainloop(game);
    endwin();
    return (0);
}
