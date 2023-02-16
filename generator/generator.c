/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** antman
*/

#include "my.h"

void gen_perf_maze(char **maze, int x, int y)
{
    maze[y][x] = '*';
    int rand_digit[4] = {1, 2, 3, 4};
    melanger(rand_digit, 4);
    for (int i = 0; i < 4; i++) {
        if (rand_digit[i] == 1)
            go_right(maze, x, y);
        if (rand_digit[i] == 2)
            go_down(maze, x, y);
        if (rand_digit[i] == 3)
            go_left(maze, x ,y);
        if (rand_digit[i] == 4)
            go_up(maze, x, y);
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    srand(time(NULL));
    char **maze = malloc_2d_array(my_getnbr(argv[2]), my_getnbr(argv[1]));
    fill_maze(maze, my_getnbr(argv[2]) ,my_getnbr(argv[1]));
    gen_perf_maze(maze, rand() % my_getnbr(argv[1]),
    rand() % my_getnbr(argv[2]));
    connect_begin_end(maze, my_getnbr(argv[1]), my_getnbr(argv[2]));
    make_it_unperfect(argv, maze, my_getnbr(argv[1]), my_getnbr(argv[2]));
    my_show_maze(maze, my_getnbr(argv[1]));
    free_array(maze, my_len_of_array(maze));
    return 0;
}
