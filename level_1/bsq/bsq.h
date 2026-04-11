/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:58:40 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/07 14:47:58 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>

typedef struct s_elements
{
	int n_lines;
	char empty;
	char obstacle;
	char full;
} t_elements;


typedef struct s_map
{
	char **grid;
	int width;
	int height;
} t_map;

typedef struct s_square
{
	int x;
	int y;
	int size;
} t_square;

int load_elements(FILE *file, t_elements *elements);
void free_grid (t_map *map);
char *ft_substr(char *line, int posx);
int verify_lines(t_map *map, t_elements *elements);
int load_map(FILE *file, t_map *map, t_elements *elements);
void print_filled_square(t_map *map, t_elements *elements, t_square *square);
int execute_bsq(FILE *file);
int my_min(int x, int y, int z);
void bsq(t_map *map, t_elements *elements, t_square *square);
int convert_file_to_pointer(char *name);
#endif