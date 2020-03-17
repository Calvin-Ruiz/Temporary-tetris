/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.c
*/

#include <game.h>

void update_game(game_t *self)
{
    static vec_t movement = {0, 1};

    if (move_piece(self->actual, self->game_zone, &movement)) {
        fix_piece(self->actual, self->game_zone);
        self->actual = self->preview;
        self->data_box->nb_lines += get_lines_filled(self->game_zone);
    }
    draw_game_zone(self->game_zone);
}
