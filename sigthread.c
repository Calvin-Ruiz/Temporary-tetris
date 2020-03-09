/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** sigthread.c
*/
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void *sigthread_run(int sig)
{
    static void (*f[32])(void);
    if (sig == -1)
}

void sigthread_launch(int sig, void *ptr, void (*f)(void *ptr))
{
    signal();
    kill(getpid(), sig);
}

void my_mutex(char state)
{
    static char actual = 0;

    if (state) {
        while (actual)
            usleep(100);
    }
    actual = state;
}
