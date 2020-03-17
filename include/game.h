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
    vec_t preview_pos;
    piece_t *preview;
    piece_t *actual;
    piece_t *pieces;
    uchar_t nb_pieces;
    controls_t controls;
} game_t;

#endif /* GAME_H_ */
