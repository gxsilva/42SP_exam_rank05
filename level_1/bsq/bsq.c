#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "bsq.h"

int load_elements(FILE *file, t_elements *elements)
{
	int res = fscanf(file, "%d %c %c %c", &(elements->n_lines), &(elements->empty), &(elements->obstacle), &(elements->full));
	if (res != 4)
		return (0);
	
	if(elements->n_lines <= 0)
		return (0);
	if (elements->empty == elements->full || elements->empty == elements->obstacle || elements->full == elements->obstacle)
		return (0);
	if (elements->empty < 32 || elements->empty > 126)
		return (0);
	if (elements->full < 32 || elements->full > 126)
		return (0);
	return (1);
}

void free_grid (t_map *map)
{
	if (!map || !map->grid)
		return ;
	for (int i = 0; i < map->height; i++)
		if (map->grid[i])
			free(map->grid[i]);
	if (map->grid)
		free(map->grid);
}

char *ft_substr(char *line, int posx)
{
	char *new_line = (char *)malloc(sizeof(char) * (posx + 1));
	if (!new_line)
		return NULL;
	for (int i = 0; i < posx; i++)
		new_line[i] = line[i];
	new_line[posx] = '\0';
	return (new_line);
}

int verify_lines(t_map *map, t_elements *elements)
{
	for (int y = 0;y < map->height; y++)
		for (int x = 0;x < map->width; x++)
			if(map->grid[y][x] != elements->empty && map->grid[y][x] != elements->obstacle)
				return (0);
	return (1);
}

int load_map(FILE *file, t_map *map, t_elements *elements)
{
	map->height = elements->n_lines;
	map->grid = (char **)malloc(sizeof(char *) * map->height);
	if (!map->grid)
		return (0);
	for (int i = 0; i < map->height; i++)
		map->grid[i] = NULL;
	char *line = NULL;
	size_t read = 0;
	ssize_t len;

	len = getline(&line, &read, file);
	if (len == -1)
		return (free(line), free_grid(map), 0);
	for (int i = 0; i < map->height; i++)
	{
		len = getline(&line, &read, file);
		if (len == -1)
			return (free(line), free_grid(map), 0);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
			len--;
		}
		char *new_line = ft_substr(line, (int)len);
		if (!new_line)
			return (free(line), free_grid(map), 0);
		map->grid[i] = new_line;
		if (i == 0)
			map->width = (int)len;
		else if ((int)len != map->width)
			return (free(line), free_grid(map), 0);
	}
	if (!verify_lines(map, elements))
		return (free(line), free_grid(map), 0);
	free(line);
	return (1);
}

void print_filled_square(t_map *map, t_elements *elements, t_square *square)
{
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			if ((y >= square->y && y <= (square->y + square->size)) && (x >= square->x && x <= (square->x + square->size)))
				fprintf(stdout, "%c", elements->full);
			else
				fprintf(stdout, "%c", map->grid[y][x]);
		}
		fprintf(stdout, "%c", '\n');
	}
}

int execute_bsq(FILE *file)
{
	t_elements elements;

	if (!load_elements(file, &elements))
		return (0);
	t_map map;

	if (!load_map(file, &map, &elements))
		return (0);
	t_square square;
	square.size = 0;
	square.x = 0;
	square.y = 0;
	bsq(&map, &elements, &square);
	print_filled_square(&map, &elements, &square);
	free_grid(&map);
	return (1);
}

int my_min(int x, int y, int z)
{
	if (x <= y && x <= z)
		return (x);
	else if (y <= z && y <= x)
		return (y);
	else
		return z;
}

void bsq(t_map *map, t_elements *elements, t_square *square)
{
	int map_tmp[map->height][map->width];

	for (int y1 = 0; y1 < map->height; y1++)
		for (int x1 = 0; x1 < map->width; x1++)
			map_tmp[y1][x1] = 0;

	for(int y = 0; y < map->height; y++)
	{
		for(int x = 0; x < map->width; x++)
		{
			if (map->grid[y][x] == elements->obstacle)
				map_tmp[y][x] = 0;
			else if (y == 0 || x == 0)
				map_tmp[y][x] = 1;
			else
			{
				int min_val = my_min(map_tmp[y][x - 1], map_tmp[y - 1][x], map_tmp[y - 1][x - 1]);
				map_tmp[y][x] = min_val + 1;
			}

			if (map_tmp[y][x] > square->size)
			{
				square->size = map_tmp[y][x];
				square->y = y - map_tmp[y][x] + 1;
				square->x = x - map_tmp[y][x] + 1;
			}
		}
	}
}

int convert_file_to_pointer(char *name)
{
	FILE *file = fopen(name, "r");
	if (!file)
		return (0);
	int ret = execute_bsq(file);
	fclose(file);
	return (ret);
}