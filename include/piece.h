/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** piece.h
*/

#ifndef PIECE_H_
#define PIECE_H_

#include <main.h>
#include <game_zone.h>

typedef struct piece {
    vec_t size;
    vec_t pos;
    uchar_t dir;
    uchar_t color;
    uchar_t *display[4];
} piece_t;

piece_t *clone_piece(piece_t *piece, const ushort_t x_len);
char move_piece(piece_t *self, game_zone_t *zone, vec_t *mvt);
char rotate_piece(piece_t *self, game_zone_t *zone);
void fix_piece(piece_t *self, game_zone_t *zone);
void display_piece(piece_t *self, game_zone_t *zone);

static inline uchar_t *spacefilled_malloc(size_t size)
{
    uchar_t *str = malloc(size);
    uchar_t *tmp = str;

    if (str == NULL)
        exit(84);
    while (size-- > 0)
        *(tmp++) = ' ';
    return (str);
}

static inline char my_check_pos(piece_t *self, game_zone_t *zone)
{
    uchar_t *display = self->display[self->dir];
    char my_if = 0;

    if (self->pos.x > zone->size.x - self->size.x
        || self->pos.y > zone->size.y - self->size.y)
        return (1);
    for (ushort_t y = self->pos.y; y < self->pos.y + self->size.y; y++) {
        for (ushort_t x = self->pos.x; x < self->pos.x + self->size.x; x++) {
            my_if = my_if || (*(display++) == '*'
                && zone->display[0][y][x] == '*');
        }
        if (my_if)
            return (1);
    }
    return (0);
}   

#endif /* PIECE_H_ */
