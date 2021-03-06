/*
** EPITECH PROJECT, 2019
** Global Tools
** File description:
** tools.c
*/
#include <stdlib.h>
#include <unistd.h>
#include <tools.h>

void *my_malloc(size_t size)
{
    static char buffer[1024*64];
    static long int pos = 0;

    pos += size;
    return (buffer + pos - size);
}

char **line_to_arr(char *str, const char sep)
{
    int i = 0;
    long int nargs = 3;
    char **arr;
    char **sav;
    if (str == NULL)
        return (NULL);
    for (int j = -1; str[++j] != '\0';)
        nargs += str[j] == sep;
    arr = malloc(sizeof(char *) * nargs);
    if (arr == NULL)
        return (NULL);
    *(arr++) = (char *) (nargs - 2);
    sav = arr;
    while (str[i] != '\0') {
        *(arr++) = str + i;
        while (str[i] != '\0' && str[i++] != sep);
        str[i - (str[i] != '\0')] = '\0';
    }
    *arr = NULL;
    return (sav);
}

void my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    my_putchar('0' + nb % 10);
}

char *tmpcat(char *str1, char *str2)
{
    static char tmp[1024];
    short len = 0;

    while (*str1)
        tmp[len++] = *(str1++);
    while (*str2)
        tmp[len++] = *(str2++);
    tmp[len] = '\0';
    return (tmp);
}
