/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** antman
*/

#include "my.h"

void gen_perf_maze(char **maze, int x, int y);

void go_right(char **maze, int x, int y)
{
    if (x + 2 < my_strlen(maze[y])) {
        if (maze[y][x + 2] == 'X') {
            maze[y][x + 1] = '*';
            gen_perf_maze(maze, x + 2, y);
        }
    }
}

void go_down(char **maze, int x, int y)
{
    if (y + 2 < my_len_of_array(maze)) {
        if (maze[y + 2][x] == 'X') {
            maze[y + 1][x] = '*';
            gen_perf_maze(maze, x, y + 2);
        }
    }
}

void go_up(char **maze, int x, int y)
{
    if (y - 1 > 0) {
        if (maze[y - 2][x] == 'X') {
            maze[y - 1][x] = '*';
            gen_perf_maze(maze, x, y - 2);
        }
    }
}

void go_left(char **maze, int x, int y)
{
    if (x - 1 > 0) {
        if (maze[y][x - 2] == 'X') {
            maze[y][x - 1] = '*';
            gen_perf_maze(maze, x - 2, y);
        }
    }
}
