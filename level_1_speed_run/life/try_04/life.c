

#include "life.h"

void free_grid(t_game *game)
{
	if (!game || !game->grid)
		return ;
	for (int i = 0; i < game->height; i++)
		if (game->grid[i])
			free(game->grid[i]);
	if (game->grid)
		free(game->grid);
}

int fill_board(t_game *game)
{
	if (!game || !game->grid)
		return (0);
	char line;
	while (read(STDIN_FILENO, &line, 1) == 1)
	{
		switch (line)
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
				break;
		}
		if (game->draw)
			game->grid[game->y][game->x] = '0';
	}
	return (1);
}

int init_game(t_game *game, char **argv)
{
	if (!game || !argv)
		return (0);
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	game->x = 0;
	game->y = 0;
	game->grid = (char **)malloc(sizeof(char *) * game->height);
	if (!game->grid)
		return (0);
	for (int y = 0; y < game->height; y++)
	{
		game->grid[y] = (char *)malloc(sizeof(char) * game->width);
		if (!game->grid[y])
			return (free_grid(game), 0);
		for(int x = 0; x < game->width; x++)
			game->grid[y][x] = ' ';
	}
	return (1);
}


void print_game(t_game *game)
{
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
			putchar(game->grid[y][x]);
		putchar('\n');
	}
}

int count_neighbours(t_game *game, int x, int y)
{
	int cnt = 0;
	for (int dy = -1; dy < 2; dy++)
	{
		for (int dx = -1; dx < 2; dx++)
		{
			if (dy == 0 && dx == 0)
				continue;
			int dry = dy + y;
			int drx = dx + x;
			if (dry < 0 || dry >= game->height || drx < 0 || drx >= game->width)
				continue;
			if (game->grid[dry][drx] == '0')
				cnt++;
		}
	}
	return cnt;
}

void free_grid_v2(char **tmp, int height)
{
	if (!tmp)
		return ;
	for (int i = 0; i < height;i++)
		if (tmp[i])
			free(tmp[i]);
	if (*tmp)
		free(tmp);
}

int life(t_game *game)
{
	char **tmp_grid = (char **)malloc(sizeof(char *) * game->height);
	if (!tmp_grid)
		return (free_grid(game), 0);
	for (int y = 0; y < game->height; y++)
	{
		tmp_grid[y] = (char *)malloc(sizeof(char) * game->width);
		if (!tmp_grid[y])
			return (free_grid_v2(tmp_grid, game->height), free_grid(game), 0);
		for (int x = 0; x < game->width; x++)
			tmp_grid[y][x] = ' ';
	}
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			int cnt = count_neighbours(game, x, y);
			if (game->grid[y][x] == '0')
			{
				if (cnt == 2 || cnt == 3)
					tmp_grid[y][x] = '0';
				else
					tmp_grid[y][x] = ' ';
			}
			else
			{
				if (cnt == 3)
					tmp_grid[y][x] = '0';
				else
					tmp_grid[y][x] = ' ';
			}
		}
	}
	free_grid(game);
	game->grid = tmp_grid;
	return (1);
}
