/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 22:31:56 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/10 22:59:22 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "bsq.h"

int file_to_ptr(char *file_name)
{
	FILE *fd = fopen(file_name, "r");
	if (!fd)
		return (0);
	int exec_res = bsq_execute(fd);
	fclose(fd);
	return (exec_res);
}

int load_elements(FILE *fd, t_elements *elements)
{
	int read_res =  fscanf(fd, "%d %c %c %c", &(elements->lines), &(elements->empty), &(elements->obstacle), &(elements->full));
	if (read_res != 4)
		return (0);
	
	if (elements->lines <= 0)
		return (0);
	else if (elements->empty < 32 || elements->empty > 126)
		return (0);
	else if (elements->obstacle < 32 || elements->obstacle > 126)
		return (0);
	else if (elements->full < 32 || elements->full > 126)
		return (0);
	else if (elements->empty == elements->full || elements->empty == elements->obstacle || elements->full == elements->obstacle)
		return (0);
	return (1);
}

void free_grid (char **board, int height)
{
	if (!board)
		return ;
	for (int i = 0; i < height; i++)
		if (board[i])
			free(board[i]);
	free(board);
}

char *ft_substr(char *line, int line_size)
{
	char *new_line = (char *)malloc(sizeof(char)  * (line_size + 1));
	if (!new_line)
		return (NULL);
	int i = 0;
	while(line[i] != '\0' && line[i] != '\n' && i < line_size)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int verify_line(char *line, t_elements *elements)
{
	for (int i = 0; line[i] != '\0'; i++)
		if (line[i] != elements->empty && line[i] != elements->full && line[i] != elements->obstacle)
			return (0);
	return (1);
}

int load_map(FILE *fd, t_grid *grid, t_elements *elements)
{
	grid->height = elements->lines;
	grid->board = (char **)malloc(sizeof(char *) * grid->height);
	if (!grid->board)
		return (0);
	for (int i = 0 ; i < grid->height;i++)
		grid->board[i] = NULL;

	char *line;
	int b_read = 0;
	size_t len = 0;
	b_read = getline(&line, &len, fd);
	if (b_read == -1)
		return (free(line), free_grid(grid->board, grid->height), 0);

	// ! verificar se o line deve tomar um free antes da proxima iteração no loop
	for (int i = 0; i < grid->height; i++)
	{
		b_read = getline(&line, &len, fd);
		if (b_read == -1)
			return (free(line), free_grid(grid->board, grid->height), 0);
		char *line_m = ft_substr(line, b_read);
		if (!line_m)
			return (free(line), free_grid(grid->board, grid->height), 0);
		grid->board[i] = line_m;
		
		if (i == 0)
			grid->width = b_read;
		else
			if (b_read != grid->width)
				return (free(line), free_grid(grid->board, grid->height), 0);
		if (!verify_line(grid->board[i], elements))
			return (free(line), free_grid(grid->board, grid->height), 0);
	}
	if (line)
		free(line);
	return (1);
}

int my_min(int x, int y, int z)
{
	if (x  < y && x < z)
		return x;
	else if (z < y)
		return z;
	else
		return y;
}

int bsq(t_grid *grid, t_elements *elements, t_square *square)
{
	int board_tmp[grid->height][grid->width];
	for (int y = 0; y < grid->height; y++)
		for (int x =0; x < grid->width; x++)
			board_tmp[y][x] = 0;
	
	for (int y = 0; y < grid->height; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if (grid->board[y][x] == elements->obstacle)
				board_tmp[y][x] = 0;
			else if (x == 0 || y == 0)
				board_tmp[y][x] = 1;
			else
			{
				int min = my_min(board_tmp[y-1][x], board_tmp[y-1][x-1], board_tmp[y][x-1]);
				board_tmp[y][x] = min + 1;
			}

			if (board_tmp[y][x] > square->size)
			{
				square->size = board_tmp[y][x];
				square->y = y - board_tmp[y][x] + 1;
				square->x = x - board_tmp[y][x] + 1;
			}
		}
	}

	return (1);
}

void print_grid(t_grid *grid, t_elements *elements, t_square *square)
{
	for (int y = 0; y < grid->height; y++)
		{
			for (int x = 0; x < grid->width; x++)
			{
				if ((y >= square->y && y < (square->y + square->size)) && (x >= square->x && x < square->x + square->size))
					fprintf(stdout, "%c", elements->full);
				else
					fprintf(stdout, "%c", grid->board[y][x]);
			}
			fprintf(stdout, "%c", '\n');
		}
}

int bsq_execute(FILE *fd)
{
	t_elements elements;
	if (!load_elements(fd, &elements))
		return (0);
	t_grid grid;
	if (!load_map(fd, &grid, &elements))
		return (0);
	t_square square;
	square.size = 0;
	square.x = 0;
	square.y = 0;
	bsq(&grid, &elements, &square);
	print_grid(&grid, &elements, &square);
	free_grid(grid.board, grid.height);
	return (1);
}