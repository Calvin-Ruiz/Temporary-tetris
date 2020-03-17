/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game_zone.h
*/

#ifndef GAME_ZONE_H_
#define GAME_ZONE_H_

typedef struct game_zone {
    vec_t pos;
    vec_t size;
    uchar_t **display[8];
} game_zone_t;

void draw_game_zone(game_zone_t *self);
void remove_line(game_zone_t *self, ushort_t y);
uchar_t get_lines_filled(game_zone_t *self);

static inline void sub_draw_game_zone(const game_zone_t * const self,
    char **display)
{
    for (ushort_t y = self->pos.y; y < self->pos.y + self->size.y;) {
        mvaddstr(y++, self->pos.x, *(display++));
    }
}

static inline uchar_t is_line_full(uchar_t *str, const ushort_t x_max)
{
    for (ushort_t x = 0; x < x_max; x += 2) {
        if (str[x] != '*')
            return (0);
    }
    return (1);
}

static inline void remove_line_in_layer(uchar_t **layer, ushort_t y, ushort_t x)
{
    uchar_t *line = layer[y];

    while (y-- > 0)
        layer[y + 1] = layer[y];
    while (--x > 0)
        line[x] = ' ';
    *layer = line;
}

#endif /* GAME_ZONE_H_ */
