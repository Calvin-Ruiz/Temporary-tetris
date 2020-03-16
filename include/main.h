/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.h
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

typedef unsigned char uchar_t;
typedef unsigned short ushort_t;
typedef unsigned int uint_t;
typedef unsigned long int ulong_t;
typedef uint_t rawvec_t;

typedef struct vector {
    ushort_t x;
    ushort_t y;
} vec_t;

typedef struct piece {
    vec_t size;
    vec_t pos;
    uchar_t dir;
    uchar_t color;
    uchar_t *display[4];
} piece_t;

typedef struct game_zone {
    vec_t pos;
    vec_t size;
    uchar_t **display[8];
} game_zone_t;

typedef struct controls {
    chtype key_left;
    chtype key_right;
    chtype key_turn;
    chtype key_drop;
    chtype key_quit;
    chtype key_pause;
} controls_t;

typedef struct data_box {
    vec_t pos;
    ushort_t high_score;
    ushort_t score;
    ushort_t nb_lines;
    uchar_t level;
    clock_t time;
} data_box_t;

typedef struct params {
    uchar_t help;
    uchar_t debug;
    uchar_t no_next;
} param_t;

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

#endif /* MAIN_H_ */
