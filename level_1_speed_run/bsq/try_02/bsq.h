/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:20:18 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/13 18:25:47 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <unistd.h>
#include <stdio.h>

typedef struct s_elements
{
	int n_lines;
	char empty;
	char obstacle;
	char full;
} t_elements;

typedef struct s_grid
{
	int width;
	int heigth;
	char **grid;
} t_grid;

typedef struct s_square
{
	int size;
	int x;
	int y;
} t_square;

int fill_elements(FILE *file, t_elements *elements);
void free_grid(t_grid *grid, int height);
char *ft_subtr(char *line, int size);
int verify_char(char *line, t_elements *elements);
int fill_grid(FILE *file, t_elements *elements, t_grid *grid);
void free_grid2(int **grid, int height);
int my_min(int x, int y, int z);
int bsq (t_elements *elements, t_grid *grid, t_square *square);
void print_grid(t_elements *elements, t_grid *grid, t_square *square);
int execute_bsq(FILE *file);
int fileToPtr(char *file);

#endif