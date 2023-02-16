/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** maze
*/

#include "my.h"

int solve_maze(char **maze, int x, int y, maze_t *maze_t);

int solve_right(char **maze, int x, int y, maze_t *m)
{
    int path = 0;
    if (x + 1 < m->len_x + 1) {
        if (maze[y][x + 1] == '*') {
            path = solve_maze(maze, x + 1, y, m);
        }
    }
    return path;
}

int solve_down(char **maze, int x, int y, maze_t *m)
{
    int path = 0;
    if (y + 1 < m->len_y + 1) {
        if (maze[y + 1][x] == '*') {
            path = solve_maze(maze, x, y + 1, m);
        }
    }
    return path;
}

int solve_up(char **maze, int x, int y, maze_t *m)
{
    int path = 0;
    if (y - 1 >= 0) {
        if (maze[y - 1][x] == '*') {
            path = solve_maze(maze, x, y - 1, m);
        }
    }
    return path;
}

int solve_left(char **maze, int x, int y, maze_t *m)
{
    int path = 0;
    if (x - 1 >= 0) {
        if (maze[y][x - 1] == '*') {
            path = solve_maze(maze, x - 1, y, m);
        }
    }
    return path;
}
