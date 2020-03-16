/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** piece.c
*/

#include <main.h>
#include <piece.h>

piece_t *clone_piece(piece_t *piece, const ushort_t x_len)
{
    piece_t *new = malloc(sizeof(piece_t));

    if (new) {
        *new = *piece;
        new->pos.x = (x_len - new->size.x) >> 1;
    }
    return (new);
}

char move_piece(piece_t *self, game_zone_t *zone, vec_t *mvt)
{
    self->pos.x += mvt->x;
    self->pos.y += mvt->y;
    if (my_check_pos(self, zone)) {
        self->pos.x -= mvt->x;
        self->pos.y -= mvt->y;
        return (0);
    }
    return (1);
}

char rotate_piece(piece_t *self, game_zone_t *zone)
{
    ushort_t tmp = self->size.x;

    self->dir = (self->dir + 1) & 3;
    self->size.x = self->size.y;
    self->size.y = tmp;
    if (my_check_pos(self, zone)) {
        self->size.y = self->size.x;
        self->size.x = tmp;
        self->dir = (self->dir - 1) & 3;
        return (0);
    }
    return (1);
}

void fix_piece(piece_t *self, game_zone_t *zone)
{
    uchar_t *display = self->display[self->dir];

    for (ushort_t y = self->pos.y; y < self->pos.y + self->size.y; y++) {
        for (ushort_t x = self->pos.x; x < self->pos.x + self->size.x; x += 2) {
            zone->display[0][y][x] = (*display == '*')
                ? '*' : zone->display[0][y][x];
            zone->display[self->color][y][x] = (*(display++) == '*')
                ? '*' : zone->display[self->color][y][x];
        }
    }
    free(self);
}
