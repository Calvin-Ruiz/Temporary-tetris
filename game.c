/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** game.c
*/

#include <game.h>
#include <map.h>

game_t *create_game(controls_t *controls)
{
    static game_t new;
    static data_box_t data = {(vec_t) {23, 10}, 0, 0, 0, 1, 0};

    new.data_box = &data;
    new.game_zone = create_game_zone();
    new.controls = controls;
    new.preview = NULL;
    new.actual = NULL;
    new.is_running = 1;
    new.is_paused = 0;
    new.display_next = 1;
    new.last = 0;
    return (&new);
}

void init_game(game_t *self, char display_next)
{
    init_game_zone(self->game_zone);
    self->preview_pos.x = 0;
    self->preview_pos.y = 19;
    self->display_next = display_next;
}

static void display_next_end(game_t *self, vec_t *pos)
{
    uchar_t *display = self->preview->display[0];
    ushort_t i = -1;

    mvaddch(pos->y, pos->x, '\\');
    while (++i <= self->preview->size.x * 2)
        addch('-');
    addch('/');
    attrset(COLOR_PAIR(self->preview->color));
    for (ushort_t y = 0; y++ < self->preview->size.y;) {
        for (ushort_t x = 0; x < self->preview->size.x; x++)
            mvaddch(y + self->preview_pos.y, x * 2 + pos->x + 2, *(display++));
    }
}

void display_next(game_t *self)
{
    vec_t pos = self->preview_pos;
    ushort_t i = -1;

    attrset(COLOR_PAIR(0));
    while (self->actual->size.y + 2 > ++i)
        mvaddstr(pos.y + i, pos.x, "                                 ");
    mvaddch(pos.y, pos.x, '/');
    i = -1;
    while (++i <= self->preview->size.x * 2)
        addch('-');
    addch('\\');
    mvaddstr(pos.y, pos.x + 1, (self->preview->size.x < 2) ? "nxt" : "-next");
    while (pos.y++ < self->preview->size.y + self->preview_pos.y) {
        mvaddch(pos.y, pos.x, '|');
        mvaddch(pos.y, pos.x + self->preview->size.x * 2 + 2, '|');
    }
    display_next_end(self, &pos);
}

void update_game(game_t *self)
{
    static vec_t movement = {0, 1};
    uchar_t filled = 0;

    if (move_piece(self->actual, self->game_zone, &movement)) {
        fix_piece(self->actual, self->game_zone);
        self->actual = self->preview;
        self->is_running = !my_check_pos(self->actual, self->game_zone);
        self->preview = clone_piece(self->pieces[clock() % self->nb_pieces],
            self->game_zone->size.x >> 1);
        if (self->display_next)
            display_next(self);
        filled = get_lines_filled(self->game_zone);
        self->data_box->nb_lines += filled;
        self->data_box->score += filled * SCORE_PER_LINE;
        self->data_box->level = self->data_box->nb_lines / 10 + 1;
        self->delta_time = CLOCKS_PER_SEC / self->data_box->level;
    }
    draw_game_zone(self->game_zone, self->actual);
}
