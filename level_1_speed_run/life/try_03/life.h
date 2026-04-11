#ifndef LIFE_H
#define LIFE_H

typedef struct s_game
{
	int width;
	int height;
	int iteractions;

	char dead;
	char alive;

	int draw;

	int x;
	int y;
	char **board;
} t_game;

#endif