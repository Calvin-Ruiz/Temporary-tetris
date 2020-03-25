/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.c
*/

#include <game.h>
#include <map.h>

game_t *create_game(controls_t *controls)
{
    static game_t new;
    static data_box_t data = {(vec_t) {23, 10}, 0, 0, 0, 1, 0};

    new.data_box = &data;
    new.game_zone = create_game_zone();
    new.controls = controls;
    new.preview = NULL;
    new.actual = NULL;
    new.is_running = 1;
    new.is_paused = 0;
    new.display_next = 1;
    new.last = 0;
    return (&new);
}

void update_game(game_t *self)
{
    static vec_t movement = {0, 1};
    uchar_t filled = 0;

    if (move_piece(self->actual, self->game_zone, &movement)) {
        fix_piece(self->actual, self->game_zone);
        self->actual = self->preview;
        self->is_running = !my_check_pos(self->actual, self->game_zone);
        self->preview = clone_piece(self->pieces[clock() % self->nb_pieces],
            self->game_zone->size.x >> 1);
        filled = get_lines_filled(self->game_zone);
        self->data_box->nb_lines += filled;
        self->data_box->score += filled * SCORE_PER_LINE;
        self->data_box->level = self->data_box->nb_lines / 10 + 1;
        self->delta_time = CLOCKS_PER_SEC / self->data_box->level;
    }
    draw_game_zone(self->game_zone, self->actual);
}
