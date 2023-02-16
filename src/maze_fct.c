/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** dante's
*/

#include "my.h"

void my_show_maze(char **tab, int x)
{
    int len = my_len_of_array(tab);
    while (*tab) {
        write(1, *tab, x);
        len--;
        tab++;
        if (len != 0)
            my_putchar(10);
    }
    return;
}
