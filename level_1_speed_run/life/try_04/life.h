#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_game
{
	int width;
	int height;
	int iterations;

	int x;
	int y;
	int draw;

	char **grid;
} t_game;

int init_game(t_game *game, char **argv);
void free_grid(t_game *game);
int fill_board(t_game *game);
void print_game(t_game *game);
int count_neighbours(t_game *game, int x, int y);
void free_grid_v2(char **tmp, int height);
int life(t_game *game);

#endif