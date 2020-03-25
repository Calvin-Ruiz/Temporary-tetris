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
#include <tools.h>
#include <time.h>

typedef unsigned char uchar_t;
typedef unsigned short ushort_t;
typedef unsigned int uint_t;
typedef unsigned long int ulong_t;
typedef uint_t rawvec_t;

typedef struct vector {
    ushort_t x;
    ushort_t y;
} vec_t;

typedef struct controls {
    long key_left;
    long key_right;
    long key_turn;
    long key_drop;
    long key_quit;
    long key_pause;
} controls_t;

typedef struct params {
    uchar_t help;
    uchar_t debug;
    uchar_t no_next;
} param_t;

#endif /* MAIN_H_ */
