/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.c
*/

#include <game.h>
#include <time.h>
#include <map.h>

game_t *create_game(controls_t *controls)
{
    static game_t new;

    new.data_box = create_data_box();
    new.game_zone = create_game_zone();
    new.controls = controls;
    new.preview = NULL;
    new.actual = NULL;
    new.is_running = 1;
    return (&new);
}

void update_game(game_t *self)
{
    static vec_t movement = {0, 1};

    if (move_piece(self->actual, self->game_zone, &movement)) {
        fix_piece(self->actual, self->game_zone);
        self->actual = self->preview;
        self->data_box->nb_lines += get_lines_filled(self->game_zone);
        self->data_box->level = self->data_box->nb_lines / 10;
        self->delta_time = CLOCKS_PER_SEC / self->data_box->level;
    }
    draw_game_zone(self->game_zone);
}
