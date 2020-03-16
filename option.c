/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** option.c
*/

#include <stddef.h>
#include <dict.h>
#include <option.h>

static void init_dict_of_option_catcher(option_t *option, controls_t *controls,
    param_t *params)
{
    append_to_dict(&option->basics, "--key-left", &controls->key_left);
    append_to_dict(&option->basics, "--key-right", &controls->key_right);
    append_to_dict(&option->basics, "--key-turn", &controls->key_turn);
    append_to_dict(&option->basics, "--key-drop", &controls->key_drop);
    append_to_dict(&option->basics, "--key-quit", &controls->key_quit);
    append_to_dict(&option->basics, "--key-pause", &controls->key_pause);
    append_to_dict(&option->basics, "--level", &option->level);
    append_to_dict(&option->basics, "--map-size", &option->size);
    append_to_dict(&option->single, "-l", &controls->key_left);
    append_to_dict(&option->single, "-r", &controls->key_right);
    append_to_dict(&option->single, "-t", &controls->key_turn);
    append_to_dict(&option->single, "-d", &controls->key_drop);
    append_to_dict(&option->single, "-q", &controls->key_quit);
    append_to_dict(&option->single, "-p", &controls->key_pause);
    append_to_dict(&option->single, "-L", &option->level);
    append_to_dict(&option->bools, "--help", &params->help);
    append_to_dict(&option->bools, "--without-next", &params->no_next);
    append_to_dict(&option->bools, "-w", &params->no_next);
    append_to_dict(&option->bools, "--debug", &params->debug);
    append_to_dict(&option->bools, "-D", &params->debug);
}

option_t *init_option_catcher(controls_t *controls, param_t *params)
{
    static option_t option = {NULL, NULL, NULL, NULL, NULL};

    init_dict_of_option_catcher(&option, controls, params);
    return (&option);
}

static char apply_word_option(option_t *option, char **av)
{
    char **word;

    for (uchar_t i = -1; (*av)[++i];) {
        if ((*av)[i] != '=')
            continue;
        (*av)[i] = '\0';
        word = get_from_dict(option->basics, *av);
        if (word == NULL)
            exit(84);
        *word = *av + i + 1;
        return;
    }
    exit(84);
}

char apply_option(option_t *option, char **av)
{
    char *my_bool = get_from_dict(option->bools, *av);
    char **word = get_from_dict(option->single, *av);

    if (my_bool) {
        *my_bool = 1;
        return (1);
    }
    if (word) {
        if (av[1] == NULL)
            exit(84);
        *word = av[1];
        return (2);
    }
    return (apply_word_option(option, av));
}

void destroy_option_catcher(option_t *option)
{
    destroy_dict(option->single, NULL);
    destroy_dict(option->basics, NULL);
    destroy_dict(option->bools, NULL);
}
