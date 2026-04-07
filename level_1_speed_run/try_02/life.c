/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:10:04 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/07 12:40:36 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "life.h"

void free_board (t_game *game)
{
	if (!game->board || !*game->board)
		return ;
	for (int y = 0; y < game->heigth; y++)
		if(game->board[y])
			free(game->board[y]);
	if (game->board)
		free(game->board);
	game->board = NULL;
}

void free_board_v2 (int **board, int heigth)
{
	if (!board || !*board)
		return ;
	for (int y = 0; y < heigth; y++)
		if(board[y])
			free(board[y]);
	if (board)
		free(board);
	board = NULL;
}


int init_game(t_game *game, char **argv)
{
	if (!game)
		return (0);
	game->witdth = atoi(argv[1]);
	game->heigth = atoi(argv[2]);
	game->iteractions = atoi(argv[3]);
	game->alive = '0';
	game->dead = ' ';
	game->x = 0;
	game->y = 0;
	game->draw = 0;

	game->board = (int **)malloc(sizeof(int *) * game->heigth);
	if (!game->board)
		return (free_board(game), 0);
	for (int i = 0; i < game->heigth; i++)
	{
		game->board[i] = (int *)malloc(sizeof(int) * game->witdth);
		if (!game->board[i])
			return (free_board(game), 0);
		for (int x = 0; x < game->witdth; x++)
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
				if (game->y > 0)
					game->y--;
				break;
			case 's':
				if (game->y < game->heigth)
					game->y++;
				break;
			case 'a':
				if (game->x > 0)
					game->x--;
				break;
			case 'd':
				if (game->x < game->witdth)
					game->x++;
				break;
			case 'x':
				if (game->draw)
					game->draw = 0;
				else
					game->draw = 1;
				break;
			default:
				break;
		}
		if (game->draw)
			game->board[game->y][game->x] = game->alive;
	}
}

void print_board(t_game *game)
{
	if (!game)
		return ;
	for (int y = 0; y < game->heigth; y++)
	{
		for (int x = 0; x < game->witdth; x++)
			putchar(game->board[y][x]);
		putchar('\n');
	}
}

int cnt_neighbours(t_game *game, int x, int y)
{
	int cnt = 0;
	for (int dy = -1; dy < 2; dy++)
	{
		for (int dx = -1; dx < 2; dx++)
		{
			if (dy == 0 && dx == 0)
				continue;
			int dyr = dy + y;
			int dxr = dx + x;
			if (dyr < 0 || dyr >= game->heigth || dxr < 0 || dxr >= game->witdth)
				continue;
			if (game->board[dyr][dxr] == game->alive)
				cnt++;
		}
	}
	return cnt;
}

int run_game(t_game *game)
{
	int **tmp_board = (int **)malloc(sizeof(int *) * game->heigth);
	if (!tmp_board)
		return (free_board_v2(tmp_board, game->heigth), 0);
	for (int y = 0; y < game->heigth; y++)
	{
		tmp_board[y] = (int *)malloc(sizeof(int) * game->witdth);
		if (!tmp_board)
			return (free_board_v2(tmp_board, game->heigth), 0);
	}
	if (!game)
		return (1);
	for (int y = 0; y < game->heigth; y++)
	{
		for (int x = 0; x < game->witdth; x++)
		{
			int counter = cnt_neighbours(game, x, y);
			if (game->board[y][x] == game->alive)
			{
				if (counter == 2 || counter == 3)
					tmp_board[y][x] = game->alive;
				else
					tmp_board[y][x] = game->dead;
			}
			else
			{
				if (counter == 3)
					tmp_board[y][x] = game->alive;
				else
					tmp_board[y][x] = game->dead;
			}
		}
	}
	free_board(game);
	game->board = tmp_board;
	return (1);
}