/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** solver.c
*/

#include "my.h"

enum direction {UP = -10, RIGHT = -11, DOWN = -12, LEFT = -13};

void set_shortest_direction(int x, int y, int *direction, maze_t *maze_t)
{
    int direction_x = maze_t->len_x - x;
    int direction_y = maze_t->len_y - y;
    if (direction_x > direction_y) {
        direction[0] = RIGHT;
        direction[1] = DOWN;
        direction[2] = UP;
        direction[3] = LEFT;
    } else {
        direction[0] = DOWN;
        direction[1] = RIGHT;
        direction[2] = LEFT;
        direction[3] = UP;
    }
}

int solve_maze(char **maze, int x, int y, maze_t *m)
{
    maze[y][x] = ' ';
    if (x == m->len_x && y == m->len_y) {
        maze[y][x] = 'o';
        m->path_found = 1;
        return 1;
    } if (m->path_found == 1) return 0;
    int direction_order[4] = {0, 0, 0, 0};
    set_shortest_direction(x, y, direction_order, m);
    int path = 0;
    for (int i = 0; i < 4; i++) {
        if (direction_order[i] == RIGHT)
            path += solve_right(maze, x, y, m);
        if (direction_order[i] == DOWN)
            path += solve_down(maze, x, y, m);
        if (direction_order[i] == LEFT)
            path += solve_left(maze, x ,y, m);
        if (direction_order[i] == UP)
            path += solve_up(maze, x, y, m);
    } if (path > 0) maze[y][x] = 'o';
    return path;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    char **maze = file_into_2d_array(argv[1]);
    maze_t maze_t;
    maze_t.len_x = my_strlen(maze[0]) - 1;
    maze_t.len_y = my_len_of_array(maze) - 1;
    maze_t.path_found = 0;
    solve_maze(maze, 0, 0, &maze_t);
    get_only_true_path(maze, &maze_t);
    my_show_maze(maze, my_strlen(maze[0]));
    free_array(maze, my_len_of_array(maze));
    return 0;
}
