/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:26:50 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/01 22:33:55 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void free_board(t_game *game)
{
	if (!game || !game->board)
		return ;
	for (int i = 0; i < game->height; i++)
		if (game->board[i])
			free (game->board[i]);
	if (game->board)
		free(game->board);
}

int init_game(t_game *game, const char **argv)
{
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iteraction = atoi(argv[3]);
	game->alive = '0';
	game->dead = ' ';
	game->draw = 0;
	game->x = 0;
	game->y = 0;

	game->board = (char **)malloc(sizeof(char *) * game->width);
	if (!game->board)
	{
		free_board(game);
		return (0);
	}
	for (int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc(sizeof(char) * game->width);
		if (!game->board[i])
		{
			free_board(game);
			return (0);
		}
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = game->dead;
	}
	return (1);
}

void fill_board(t_game *game)
{
	int flag = 0;
	char buffer;

	while (read(STDIN_FILENO, &buffer, 1) != 0)
	{
		flag = 0;
		switch(buffer)
		{
			case 'w':
				if (game->y > 0)
					game->y--;
				break;
			case 's':
				if (game->y < game->height - 1)
					game->y++;
				break;
			case 'a':
				if (game->x > 0)
					game->x--;
				break;
			case 'd':
				if (game->x < game->width - 1)
					game->x++;
				break;
			case 'x':
				if (game->draw)
					game->draw = 0;
				else
					game->draw = 1;
				break;
			default:
				flag = 1;
				break;
		}
		if (flag != 1 && game->draw == 1)
			game->board[game->y][game->x] = game->alive;
	}
}

int count_neighbors(t_game *game, int y, int x)
{
	int counter = 0;
	for (int dy = -1; dy < 2; dy++)
	{
		for (int dx = -1; dx < 2; dx++)
		{
			if (dy == 0 && dx == 0)
				continue;
			int dyr = y + dy;
			int dxr = x + dx;

			if ((dyr < 0 || dyr > game->height - 1) || (dxr < 0 || dxr > game->width - 1))
				continue ;
			if (game->board[dyr][dxr] == game->alive)
				counter++;
		}
	}
	return (counter);
}

int run_game(t_game *game)
{
	char **tmp_board;

	tmp_board = (char **)malloc(sizeof(char *)  * game->height);
	if (!tmp_board)
		return (0);
	for (int i = 0; i < game->height; i++)
	{
		tmp_board[i] = (char *)malloc(sizeof(char) * game->width);
		if (!tmp_board[i])
		{
			for (int i = 0; i < game->height; i++)
				if (tmp_board[i])
					free (tmp_board[i]);
			if (tmp_board)
				free(tmp_board);
			return (1);
		}
	}
	
	int cnt_neighbors = 0;
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			cnt_neighbors = count_neighbors(game, y, x);

			if (game->board[y][x] == game->alive)
			{
				if (cnt_neighbors == 2 || cnt_neighbors == 3)
					tmp_board[y][x] = game->alive;
				else
					tmp_board[y][x] = game->dead;
			}
			else
			{
				if (cnt_neighbors == 3)
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

void	print_board(t_game *game)
{
	if (!game)
		return;
	for (int y = 0; y < game->height; y++)
	{
		for(int x = 0; x < game->width; x++)
			putchar((game->board[y][x]));
		putchar('\n');
	}
}
 

int main(int argc, const char **argv)
{
	if (argc != 4)
		return (1);
	t_game game;

	if(!init_game(&game, argv))
	{
		free_board(&game);
		return (1);
	}

	fill_board(&game);
	for (int i = 0; i < game.iteraction; i++)
	{
		if (!run_game(&game))
		{
			free_board(&game);
			return (1);
		}
	}
	print_board(&game);
	free_board(&game);
	return (0);
}