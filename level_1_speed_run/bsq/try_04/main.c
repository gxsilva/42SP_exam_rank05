#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_elements
{
	int n_lines;
	char empty;
	char obstacle;
	char full;
} t_elements;

typedef struct s_grid
{
	int height;
	int width;
	char **grid;
} t_grid;

typedef struct s_square
{
	int size;
	int x;
	int y;
} t_square;

int fill_elements(FILE *fd, t_elements *elements)
{
	if (!fd || !elements)
		return (0);
	int scan_read = fscanf(fd, "%d %c %c %c", &(elements->n_lines), &(elements->empty),&(elements->obstacle),&(elements->full));
	if (scan_read != 4)
		return (0);
	if (elements->n_lines <= 0)
		return (0);
	else if (elements->empty < 32 || elements->empty > 126)
		return (0);
	else if (elements->obstacle < 32 || elements->obstacle > 126)
		return (0);
	else if (elements->full < 32 || elements->full > 126)
		return (0);
	else if (elements->empty == elements->obstacle || elements->empty == elements->full || elements->full == elements->obstacle)
		return (0);
	return (1);
}

void free_grid(t_grid *grid)
{
	if (!grid)
		return ;
	for (int i = 0; i < grid->height; i++)
		if (grid->grid[i])
			free(grid->grid[i]);
	if (grid->grid)
		free(grid->grid);
}

int cnt_line(char *line)
{
	int size = 0;
	while (line[size] != '\0')
		size++;
	return (size);
}

char *ft_substr (char *line, int line_size)
{
	if (!line)
		return (NULL);
	char *new_str = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!new_str)
		return (NULL);
	for (int i = 0; i < line_size; i++)
		new_str[i] = line[i];
	new_str[line_size] = '\0';
	return (new_str);
}

int verify_char(char *line, t_elements *elements)
{
	if (!line || !elements)
		return (0);
	for (int i = 0;line[i] != '\0'; i++)
		if (line[i] != elements->empty && line[i] !=elements->obstacle)
			return (0);
	return (1);
}

int fill_grid(FILE *fd, t_elements *elements, t_grid *grid)
{
	if (!fd || !elements || !grid)
		return (0);
	grid->grid = (char **)malloc(sizeof(char *) * grid->height);
	if (!grid->grid)
		return (0);
	for (int i = 0; i < grid->height; i++)
		grid->grid[i] = NULL;
	char *line = NULL;
	size_t len = 0;
	int b_read = 0;
	int idx = 0;
	b_read = getline(&line, &len, fd);
	if (b_read == -1)
	{
		if (line)
			free(line);
		return (free_grid(grid), 0);
	}
	if (line)
		free(line);
	line = NULL;
	len = 0;
	while((b_read = getline(&line, &len, fd)) != -1)
	{
		if (idx >= grid->height)
		{
			if (line)
				free(line);
			return (free_grid(grid), 0);
		}
		if (line[b_read - 1] == '\n')
			line [b_read - 1] = '\0';
		int line_length = cnt_line(line);
		if (grid->width == 0)
			grid->width = line_length;
		else
		{
			if (line_length != grid->width)
			{
				if (line)
					free(line);
				return (free_grid(grid), 0);
			}
		}
		grid->grid[idx] = ft_substr(line, line_length);
		if (!grid->grid[idx])
		{
			if (line)
				free(line);
			return (free_grid(grid), 0);
		}
		if (!verify_char(grid->grid[idx], elements))
		{
			if (line)
				free(line);
			return (free_grid(grid), 0);
		}
		if (line)
			free(line);
		line = NULL;
		len = 0;
		idx++;
	}
	if (idx != grid->height)
		return (0);
	return (1);
}

void free_grid_v2(int **grid, int height)
{
	if (!grid)
		return ;
	for (int i =0 ; i < height; i++)
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

int bsq(t_grid *grid, t_elements *elements, t_square *square)
{
	if (!grid || !elements || !square)
		return (free_grid(grid), 0);
	int **tmp_board = (int **)malloc(sizeof(int *) * grid->height);
	if (!tmp_board)
		return (free_grid(grid), 0);
	for (int i = 0; i < grid->height; i++)
	{
		tmp_board[i] = (int *)(malloc(sizeof(int) * grid->width));
		if (!tmp_board[i])
			return (free_grid_v2(tmp_board, grid->height), free_grid(grid), 0);
		for (int x = 0; x < grid->width; x++)
			tmp_board[i][x] = 0;
	}
	for (int y = 0; y < grid->height; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if (grid->grid[y][x] == elements->obstacle)
				continue ;
			else if (y == 0 || x == 0)
				tmp_board[y][x] = 1;
			else
			{
				int min = my_min(tmp_board[y - 1][x - 1], tmp_board[y - 1][x], tmp_board[y][x - 1]);
				tmp_board[y][x] = min + 1;
			}

			if (tmp_board[y][x] > square->size)
			{
				square->size = tmp_board[y][x];
				square->x = x - square->size + 1;
				square->y = y - square->size + 1;
			}
		}
	}
	if (tmp_board)
		free_grid_v2(tmp_board, grid->height);
	return (1);
}

int print_grid(t_grid *grid, t_elements *elements, t_square *square)
{
	if (!grid || !elements || !square)
		return (free_grid(grid), 0);
	for (int y = 0; y < grid->height; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if (y >= square->y && y < (square->y + square->size) && x >= square->x && x < (square->x + square->size))
				fprintf(stdout, "%c", elements->full);
			else
				fprintf(stdout, "%c", grid->grid[y][x]);
		}
		fprintf(stdout, "%c", '\n');
	}
	return (1);
}

int execute_bsq(FILE *fd)
{
	if (!fd)
		return (0);
	t_elements elements;
	if (!fill_elements(fd, &elements))
		return (0);
	// printf ("elements  n_lines: %d\n", elements.n_lines);
	// printf ("elements  full: %c\n", elements.full);
	// printf ("elements  empty: %c\n", elements.empty);
	// printf ("elements  obstacle: %c\n", elements.obstacle);

	t_grid grid;
	grid.height = elements.n_lines;
	grid.width = 0;

	if (!fill_grid(fd, &elements, &grid))
		return (0);

	// printf ("grid height: %d\n", grid.height);
	// printf ("grid width: %d\n", grid.width);
	// for (int i = 0; i < grid.height; i++)
	// {
	// 	for (int x = 0; x < grid.width; x++)
	// 	{
	// 		printf("%c", grid.grid[i][x]);
	// 	}
	// 	printf("\n");
	// }


	t_square square;
	square.size = 0;
	square.x = 0;
	square.y = 0;
	if (!bsq(&grid, &elements, &square))
		return (0);

	if (!print_grid(&grid, &elements, &square))
		return (0);
	free_grid(&grid);
	return (1);
}

int fileToPtr(char *file)
{
	if (!file)
		return (0);
	FILE *fd = fopen(file, "r");
	if (!fd)
		return (0);
	if (!execute_bsq(fd))
	{
		fclose(fd);
		return (0);
	}
	fclose (fd);
	return (1);
}

int main(int argc, char **argv)
{
	int res = 0;
	if (argc < 2)
	{
		if (!execute_bsq(stdin))
		{
			fprintf(stderr, "map error\n");
			return (1);
		}
	}
	else
	{
		for (int i = 1; i < argc;i++)
		{
			if (!fileToPtr(argv[i]))
			{
				fprintf(stderr, "map error\n");
				res = 1;
			}
			if (i < argc - 1)
				fprintf(stdout, "\n");
		}
	}
	return (res);
}