/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** solver.c
*/

#include "my.h"

void delete_return_of_line(char *line)
{
    for (int i = 0; i < my_strlen(line); i++) {
       if (line[i] == '\n') {
           line[i] = '\0';
       }
    }
}

char **file_into_2d_array(char *filepath)
{
    FILE * fp; 
    char * line = NULL; 
    size_t len = 0;
    ssize_t read; fp = fopen(filepath, "r");
    if (fp == NULL) exit(84);
    int hauteur = 0; int largeur = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        hauteur++; 
        if (read > largeur) 
            largeur = read;
    }
    if (hauteur == 0 || largeur == 0)
        exit(84);
    char **maze = malloc_2d_array(hauteur, largeur);
    free(line);
    fclose(fp);
    line = NULL;
    len = 0; 
    hauteur = 0; 
    fp = fopen(filepath, "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        delete_return_of_line(line);
        my_strcpy(maze[hauteur], line); 
        hauteur++;
    }
    free(line);
    fclose(fp);
    return maze;
}

int main(int argc, char **argv)
{
    char **maze = file_into_2d_array(argv[1]);
    my_show_maze(maze, my_strlen(maze[0]));
    free_array(maze, my_len_of_array(maze));
    return 0;
}
