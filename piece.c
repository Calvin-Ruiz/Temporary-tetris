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
        new->pos.x = (x - new->size.x) >> 1;
    }
    return (new);
}

char move_piece(piece_t *self, game_zone_t *zone, vec_t *mvt)
{
    char *display = *(self->display[self->dir]);
    char my_if = 0;

    mvt->x += self->pos.x;
    mvt->y += self->pos.y;
    if (mvt->x >= zone->size.x - self->size.x)
        return (0);
    for (ushort_t y = mvt->y; y < mvt->y + self->size.y; y++) {
        for (ushort_t x = mvt->x; x < mvt->x + self->size.x; x += 2) {
            my_if = my_if || (*display == '*' && zone->display[0][y][x] == '*');
            display += 2;
        }
        if (my_if)
            return (0);
    }
    self->pos = *mvt;
    return (1);
}

void rotate_piece(piece_t *self, game_zone_t *zone)
{
    return;
}
