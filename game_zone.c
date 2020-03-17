/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game_zone.c
*/

#include <main.h>
#include <piece.h>
#include <game_zone.h>

void draw_game_zone(game_zone_t *self)
{
    for (uchar_t i = 0; ++i < 8;)
        sub_draw_game_zone(self, (char **) self->display[i]);
}

void remove_line(game_zone_t *self, ushort_t y)
{
    for (uchar_t i = 0; ++i < 8;)
        remove_line_in_layer(self->display[i], y, self->size.x);
}

uchar_t get_lines_filled(game_zone_t *self)
{
    uchar_t nb_lines;

    for (ushort_t y = 0; y < self->pos.y + self->size.y;) {
        if (is_line_full((*self->display)[y], self->size.x)) {
            remove_line(self, y);
            nb_lines++;
        }
    }
    return (nb_lines);
}
