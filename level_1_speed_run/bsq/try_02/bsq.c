/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:20:42 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/13 19:30:51 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int fill_elements(FILE *file, t_elements *elements)
{
	if (!elements || !file)
		return (0);
	int scanf_read = fscanf(file, "%d %c %c %c", &(elements->n_lines), &(elements->empty), &(elements->obstacle), &(elements->full));
	if (scanf_read != 4)
		return (0);
	
	if (elements->n_lines <= 0)
		return (0);
	else if (elements->empty < 32 || elements->empty > 126)
		return (0);
	else if (elements->obstacle < 32 || elements->obstacle > 126)
		return (0);
	else if (elements->full < 32 || elements->full > 126)
		return (0);
	else if (elements->full == elements->empty || elements->full == elements->obstacle || elements->empty == elements->obstacle)
		return (0);

	return (1);
}

void free_grid(t_grid *grid, int height)
{
	if (!grid || !grid->grid)
		return ;
	for (int i = 0; i < height; i++)
		if (grid->grid[i])
			free(grid->grid[i]);
	if (grid->grid)
		free(grid->grid);
}

char *ft_subtr(char *line, int size)
{
	char *new_line = (char *)malloc(sizeof(char) * (size + 1));
	if (!new_line)
		return NULL;
	int i = 0;
	while (line[i] != '\0' && line[i] != '\n' && i < size)
	{
		new_line[i]  = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int verify_char(char *line, t_elements *elements)
{
	if (!line || !elements)
		return (0);
	for (int i = 0; line[i] != '\0'; i++)
		if (line[i] != elements->empty && line[i] != elements->full && line[i] != elements->obstacle)
			return (0);
	return (1);
}

int fill_grid(FILE *file, t_elements *elements, t_grid *grid)
{
	if (!file || !elements || !grid)
		return (0);
	char *line = NULL;
	int b_read = 0;
	size_t length = 0;
	b_read = getline(&line, &length, file);
	if (b_read == -1)
		return (free_grid(grid, grid->heigth), 0);
	if (line)
		free(line);
	line = NULL;
	length = 0;
	for (int i = 0; i < grid->heigth; i++)
	{
		b_read = getline(&line, &length, file);
		if (b_read == -1)
			return (free(line), free_grid(grid, i), 0);
		char *tmp_line = ft_subtr(line, b_read);
		if (!tmp_line)
			return (free(line), free_grid(grid, i), 0);
		if (grid->width == 0)
			grid->width = b_read;
		else
		{
			if (grid->width != b_read)
				return (free(tmp_line), free(line), free_grid(grid, i), 0);
		}
		grid->grid[i] = tmp_line;
		if (!verify_char(grid->grid[i], elements))
			return (free(line), free_grid(grid, i + 1), 0);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
		free(line);
	return (1);
}

void free_grid2(int **grid, int height)
{
	if (!grid)
		return ;
	for (int i = 0; i < height; i++)
		if (grid[i])
			free(grid[i]);
	if (grid)
		free(grid);
}

int my_min(int x, int y, int z)
{
	if (x < y && x < z)
		return (x);
	else if (y < z)
		return (y);
	else
		return (z);
}

int bsq (t_elements *elements, t_grid *grid, t_square *square)
{
	if (!elements || !grid || !square)
		return (0);
	int **tmp_grid = (int **)malloc(sizeof(int *) * grid->heigth);
	if (!tmp_grid)
		return (0);
	for (int y = 0; y < grid->heigth; y++)
	{
		tmp_grid[y] = (int *)malloc(sizeof(int) * grid->width);
		if (!tmp_grid[y])
			return (free_grid2(tmp_grid, y), 0);
		for (int x = 0; x < grid->width; x++)
			tmp_grid[y][x] = 0;
	}
	for (int y = 0; y < grid->heigth; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if (grid->grid[y][x] == elements->obstacle)
				continue;
			if (y == 0 || x == 0)
				tmp_grid[y][x] = 1;
			else
			{
				int value = my_min(tmp_grid[y - 1][x], tmp_grid[y - 1][x - 1], tmp_grid[y][x - 1]);
				tmp_grid[y][x] = value + 1;
			}
			
			if (tmp_grid[y][x] > square->size)
			{
				square->size = tmp_grid[y][x];
				square->x = x - square->size + 1;
				square->y = y - square->size + 1;
			}
		}
	}
	free_grid2(tmp_grid, grid->heigth);
	return (1);
}

void print_grid(t_elements *elements, t_grid *grid, t_square *square)
{
	if (!elements || !grid || !square)
		return ;
	for (int y = 0; y < grid->heigth; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if ((y >= square->y && y < square->y + square->size)
				&& (x >= square->x && x < square->x + square->size))
				fprintf(stdout, "%c", elements->full);
			else
				fprintf(stdout, "%c", grid->grid[y][x]);
		}
		fprintf(stdout, "%c", '\n');
	}
}

int execute_bsq(FILE *file)
{
	t_elements elements;
	if (!fill_elements(file, &elements))
		return (0);
	t_grid grid;
	grid.heigth = elements.n_lines;
	grid.width = 0;
	grid.grid = (char **)malloc(sizeof(char *) * grid.heigth);
	if (!grid.grid)
		return (0);
	for (int i = 0; i < grid.heigth; i++)
		grid.grid[i] = NULL;
	if (!fill_grid(file, &elements, &grid))
		return (0);
	t_square square;
	square.size = 0;
	square.x = 0;
	square.y = 0;
	if(!bsq(&elements, &grid, &square))
		return (free_grid(&grid, grid.heigth), 0);
	print_grid(&elements, &grid, &square);
	free_grid(&grid, grid.heigth);
	return (1);
}

int fileToPtr(char *file)
{
	if (!file)
		return (0);
	FILE *fd = fopen(file, "r");
	if (!fd)
		return (0);
	
	if(!execute_bsq(fd))
	{
		fclose(fd);
		return (0);
	}
	fclose(fd);
	return (1);
}