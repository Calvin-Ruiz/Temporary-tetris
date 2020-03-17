/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.h
*/

#ifndef GAME_H_
#define GAME_H_

#include <piece.h>
#include <data_box.h>

typedef struct game {
    game_zone_t *game_zone;
    data_box_t *data_box;
    controls_t *controls;
    vec_t preview_pos;
    piece_t *preview;
    piece_t *actual;
    piece_t **pieces;
    uchar_t nb_pieces;
    clock_t delta_time;
    clock_t last;
    uchar_t is_running;
    uchar_t display_next;
} game_t;

void update_game(game_t *self);
void init_game(game_t *self, param_t *params);
game_t *create_game(controls_t *controls);

#endif /* GAME_H_ */
