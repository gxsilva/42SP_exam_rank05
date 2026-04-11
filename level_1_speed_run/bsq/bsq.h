#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>

typedef struct s_elements
{
	int lines;
	char empty;
	char obstacle;
	char full;
} t_elements;

typedef struct s_grid
{
	int height;
	int width;
	char **board;
} t_grid;

typedef struct s_square
{
	int x;
	int y;
	int size;
}	t_square;

int file_to_ptr(char *file_name);
int load_elements(FILE *fd, t_elements *elements);
void free_grid (char **board, int height);
char *ft_substr(char *line, int line_size);
int verify_line(char *line, t_elements *elements);
int load_map(FILE *fd, t_grid *grid, t_elements *elements);
int my_min(int x, int y, int z);
int bsq(t_grid *grid, t_elements *elements, t_square *square);
void print_grid(t_grid *grid, t_elements *elements, t_square *square);
int bsq_execute(FILE *fd);

#endif