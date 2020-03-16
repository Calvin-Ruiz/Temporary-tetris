/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** piece.h
*/

#ifndef PIECE_H_
#define PIECE_H_

piece_t *clone_piece(piece_t *piece, const ushort_t x_len);
char move_piece(piece_t *self, game_zone_t *zone, vec_t *mvt);
char rotate_piece(piece_t *self, game_zone_t *zone);

static inline char my_check_pos(piece_t *self, game_zone_t *zone, vec_t *pos)
{
    uchar_t *display = *(self->display[self->dir]);
    char my_if = 0;

    if (pos->x >= zone->size.x - self->size.x
        || pos->y >= zone->size.y - self->size.y)
        return (1);
    for (ushort_t y = pos->y; y < pos->y + self->size.y; y++) {
        for (ushort_t x = pos->x; x < pos->x + self->size.x; x += 2) {
            my_if = my_if || (*display == '*' && zone->display[0][y][x] == '*');
            display += 2;
        }
        if (my_if)
            return (1);
    }
    return (0);
}

#endif /* PIECE_H_ */
