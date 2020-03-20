/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game_zone.c
*/

#include <main.h>
#include <piece.h>
#include <game_zone.h>
#include <map.h>

game_zone_t *create_game_zone(void)
{
    static game_zone_t zone = {(vec_t) {35, 1}, (vec_t) {10, 20}, {0, 0, 0, 0}};

    return (&zone);
}

void init_game_zone(game_zone_t *zone)
{
    vec_t size = {34, 17};

    size.x += 3 + 2 * zone->size.x;
    if (zone->size.y + 2 > size.y)
        size.y = zone->size.y + 2;
    while (LINES < size.y || COLS < size.x)
        my_message(&size);
    erase();
    for (int i = -1; ++i < 8;) {
        zone->display[i] = my_malloc(sizeof(void *) * zone->size.y);
        for (int j = -1; ++j < zone->size.y;) {
            zone->display[i][j] = spacefilled_malloc(zone->size.x * 2);
        }
    }
    display_map(&zone->size);
    display_scoreboard();
    diplsay_tetris();
}

void draw_game_zone(game_zone_t *self, void *actual)
{
    attrset(COLOR_PAIR(0));
    for (ushort_t y = -1; ++y < self->size.y;)
        sub_draw_game_zone(self, (char *) self->display[0][y], y, 1);
    display_piece(actual, self);
    for (uchar_t i = 0; ++i < 8;) {
        attrset(COLOR_PAIR(i));
        for (ushort_t y = -1; ++y < self->size.y;)
            sub_draw_game_zone(self, (char *) self->display[i][y], y, 0);
    }
}

void remove_line(game_zone_t *self, ushort_t y)
{
    for (uchar_t i = 0; ++i < 8;)
        remove_line_in_layer(self->display[i], y, self->size.x);
}

uchar_t get_lines_filled(game_zone_t *self)
{
    uchar_t nb_lines;

    for (ushort_t y = -1; ++y < self->pos.y + self->size.y;) {
        if (is_line_full((*self->display)[y], self->size.x)) {
            remove_line(self, y);
            nb_lines++;
        }
    }
    return (nb_lines);
}
