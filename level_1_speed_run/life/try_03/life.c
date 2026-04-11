#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "life.h"

void free_board(char **board, int heigth)
{
	if (!board)
		return ;
	for (int x = 0; x < heigth; x++)
		if (board[x])
			free(board[x]);
	free(board);
	return ;
}

int init_game(t_game *game, char **argv)
{
	if (!game)
		return (0);
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iteractions = atoi(argv[3]);
	game->alive = '0';
	game->dead =  ' ';
	game->draw =  0;
	game->x = 0;
	game->y = 0;
	game->board = (char **)malloc(sizeof(char *) * game->height);
	if (!game->board)
		return (0);
	for (int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc(sizeof(char) * game->width);
		if (!game->board[i])
			return (free_board(game->board, game->height), 0);
		for (int x = 0; x < game->width; x++)
			game->board[i][x] = game->dead;
	}
	return (1);
}

void fill_board(t_game *game)
{
	char buffer;
	while (read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch (buffer)
		{
			case 'w':
			{
				if (game->y > 0)
					game->y--;
				break;
			}
			case 's':
			{
				if (game->y < game->height)
					game->y++;
				break;
			}
			case 'a':
			{
				if (game->x > 0)
					game->x--;
				break;
			}
			case 'd':
			{
				if (game->x < game->width)
					game->x++;
				break;
			}
			case 'x':
			{
				if (game->draw)
					game->draw = 0;
				else
					game->draw = 1;
				break;
			}
			default:
			{
				break;
			}
		}
		if (game->draw)
			game->board[game->y][game->x] = game->alive;
	}
}

int count_neighbours(t_game *game, int x, int y)
{
	int counter = 0;
	if (!game)
		return -1;
	for (int dy = -1; dy < 2; dy++)
	{
		for (int dx = -1; dx < 2; dx++)
		{
			if (dy == 0 && dx == 0)
				continue ;
			int dry = y + dy;
			int drx = x + dx;
			if (dry < 0 || dry > (game->height - 1) || drx < 0 || drx > (game->width - 1))
				continue ;
			if (game->board[dry][drx] == game->alive)
				counter++;
		}
	}
	return (counter);
}

int run_game(t_game *game)
{
	char **tmp_board = (char **)malloc(sizeof(char *) * game->height);
	if (!tmp_board)
		return (0);
	for (int i = 0; i < game->height; i++)
	{
		tmp_board[i] = (char *)malloc(sizeof(char *) * game->width);
		if (!tmp_board[i])
			return (free_board(tmp_board, game->height), 0);
	}
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			int cnt_neibourth = count_neighbours(game, x, y);
			if (cnt_neibourth == -1)
				return (free_board(tmp_board, game->height), 0);
			if (game->board[y][x] == game->alive)
			{
				if( cnt_neibourth == 2 || cnt_neibourth == 3)
					tmp_board[y][x] = game->alive;
				else
					tmp_board[y][x] = game->dead;
			}
			else
			{
				if (cnt_neibourth == 3)
					tmp_board[y][x] = game->alive;
				else
					tmp_board[y][x] = game->dead;
			}
		}
	}
	free_board(game->board, game->height);
	game->board =  tmp_board;
	return 1;
}

void print_board(t_game *game)
{
	for (int x = 0; x < game->height; x++)
	{
		for (int y = 0; y < game->width; y++)
			putchar(game->board[x][y]);
		putchar('\n');
	}
}
