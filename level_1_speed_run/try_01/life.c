/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:06:05 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 18:19:55 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void free_board(t_game *game)
{
	if (!game || !game->board)
		return ;
	for (int i = 0; i < game->heigth; i++)
		if (game->board[i])
			free(game->board[i]);
	free(game->board);
}

int init_game(t_game *game, char **argv)
{
	if (!game)
		return (0);
	game->width = atoi(argv[1]);
	game->heigth = atoi(argv[2]);
	game->iteractions = atoi(argv[3]);
	game->dead = ' ';
	game->live = '0';
	game->x = 0;
	game->y = 0;
	game->draw = 0;
	game->board = (int **)malloc(sizeof(int *) * game->heigth);
	if (!game->board)
	{
		free_board(game);
		return (0);
	}
	for (int x = 0; x < game->heigth; x++)
	{
		game->board[x] = (int *)malloc(sizeof(int) * game->width);
		if (!game->board[x])
		{
			free_board(game);
			return (0);
		}
		for (int j = 0; j < game->width; j++)
			game->board[x][j] = game->dead;
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
			case ('w'):
			{
				if (game->y > 0)
					game->y--;
				break;
			}
			case ('s'):
			{
				if (game->y < game->heigth)
					game->y++;
				break;
			}
			case ('a'):
			{
				if (game->x > 0)
					game->x--;
				break;
			}
			case ('d'):
			{
				if (game->x < game->width)
					game->x++;
				break;
			}
			case ('x'):
			{
				if (game->draw)
					game->draw = 0;
				else
					game->draw = 1;
				break;
			}
			default:
				break;
		}
		if (game->draw)
			game->board[game->y][game->x] = game->live;
	}
}

void print_board(t_game *game)
{
	for (int y = 0; y < game->heigth; y++)
	{
		for (int x = 0; x < game->width; x++)
			putchar(game->board[y][x]);
		putchar('\n');
	}
}

int count_neighbours(t_game *game, int x, int y)
{
	if (!game)
		return (-1);
	int counter = 0;
	for (int dy = -1; dy < 2; dy++)
	{
		for (int dx = -1; dx < 2; dx++)
		{
			int dry = y  + dy;
			int drx = x  + dx;
			if (dry == 0 && drx == 0)
				continue;
			if ((dry < 0) || (dry >= game->heigth) || drx < 0 || drx >= game->width)
				continue ;
			if (game->board[dry][drx] == game->live)
				counter++;
		}
	}
	return (counter);
}


int run_game(t_game *game)
{
	int **tmp_board = (int **)malloc(sizeof(int *) * game->heigth);
	if (!tmp_board)
		return (0);
	for (int i = 0; i < game->heigth; i++)
	{
		tmp_board[i] = (int *)malloc(sizeof(int) * game->width);
		if (!tmp_board[i])
		{
			for (int i = 0; i < game->heigth; i++)
				if (tmp_board[i])
					free(tmp_board[i]);
			if (tmp_board)
				free(tmp_board);
			return (0);
		}
	}

	for (int y = 0; y < game->heigth; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			int neighbours = count_neighbours(game, x, y);
			if (neighbours == -1)
			{
				for (int i = 0; i < game->heigth; i++)
				if (tmp_board[i])
					free(tmp_board[i]);
				if (tmp_board)
					free(tmp_board);
				return (0);
			}
			if (game->board[y][x] == game->live)
			{
				if(neighbours == 3 || neighbours == 2)
					tmp_board[y][x] = game->live;
				else
					tmp_board[y][x] = game->dead;
			}
			else
			{
				if (neighbours == 3)
					tmp_board[y][x] = game->live;
				else
					tmp_board[y][x] = game->dead;
			}
		}
	}
	free_board(game);
	game->board = tmp_board;
	return (1);
}
