/*
** EPITECH PROJECT, 2019
** Global Tools
** File description:
** tools.c
*/
#include <stdlib.h>
#include <unistd.h>

void *my_malloc(size_t size)
{
    static char buffer[1024*64];

    buffer += size;
    return (buffer - size);
}

char **line_to_arr(char *str)
{
    int i = -1;
    long int nargs = 2;
    char **arr;
    char **sav;
    if (str == NULL)
        return (NULL);
    while (str[++i] != '\0')
        nargs += str[i] == ':';
    arr = malloc(sizeof(char *) * nargs);
    if (arr == NULL)
        return (NULL);
    sav = arr;
    i = 0;
    *(arr++) = (char *) (nargs - 1);
    while (str[i] != '\0') {
        *(arr++) = str + i;
        while (str[i] != '\0' && str[i++] != '\n');
        str[i - (str[i] != '\0')] = '\0';
    }
    return (sav + 1);
}
