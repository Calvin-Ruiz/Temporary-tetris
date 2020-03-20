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

game_zone_t *create_game_zone(void);
void init_game_zone(game_zone_t *zone);
void draw_game_zone(game_zone_t *self, void *actual);
void remove_line(game_zone_t *self, ushort_t y);
uchar_t get_lines_filled(game_zone_t *self);

static inline void sub_draw_game_zone(const game_zone_t * const self,
    char *display, ushort_t y, char prefill)
{
    for (ushort_t x = self->pos.x; x < self->pos.x + self->size.x * 2;
        x += 2) {
        if (*(display++) == '*')
            mvaddch(y + self->pos.y, x, '*');
        if (prefill)
            mvaddch(y + self->pos.y, x, ' ');
    }
}

static inline uchar_t is_line_full(uchar_t *str, const ushort_t x_max)
{
    for (ushort_t x = 0; x < x_max * 2; x += 2) {
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

static inline void my_cute_message(void)
{
    if (COLS >= 10) {
        mvaddstr(LINES >> 1, (COLS - 10) >> 1, "more space");
        return;
    }
    if (COLS >= 6)
        mvaddstr(LINES >> 1, (COLS - 6) >> 1, "please");
    else if (COLS >= 4)
        mvaddstr(LINES >> 1, (COLS - 4) >> 1, "no !");
    else
        mvaddch(LINES >> 1, COLS >> 1, 'X');
}

static inline void my_message(vec_t *size)
{
    char str[] = "We need :     \n00 more lines \n00 more column";
    int pos[3] = {(LINES - 3) >> 1, (COLS - 14) >> 1, -1};

    erase();
    if (COLS < 14 || LINES < 3) {
        my_cute_message();
        refresh();
        return;
    }
    if (LINES < size->y) {
        str[15] = '0' + (size->y - LINES) / 10;
        str[16] = '0' + (size->y - LINES) % 10;
    }
    if (COLS < size->x) {
        str[30] = '0' + (size->x - COLS) / 10;
        str[31] = '0' + (size->x - COLS) % 10;
    }
    while (++pos[2] < 3)
        mvaddnstr(pos[0]++, pos[1], str + pos[2] * 15, 14);
    refresh();
}

#endif /* GAME_ZONE_H_ */
