#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_elements
{
	int n_lines;
	char empty;
	char obstacle;
	char full;
} t_elements;

typedef struct s_grid
{
	int heigth;
	int width;
	char **grid;
} t_grid;

typedef struct s_square
{
	int size;
	int x;
	int y;
} t_square;


int fileToPtr(char *argv);
int execute_bsq(FILE *file);
int fill_elements(t_elements *elements, FILE *fd);

int fill_elements(t_elements *elements, FILE *fd)
{
	if (!elements || !fd)
		return (0);
	int scan_read = fscanf(fd, "%d %c %c %c", &(elements->n_lines), &(elements->empty), &(elements->obstacle), &(elements->full));
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
	else if (elements->full == elements->empty || elements->full == elements->obstacle || elements->empty == elements->obstacle)
		return (0);
	return (1);
}

void free_grid(t_grid *grid)
{
	if (!grid || !grid->grid)
		return ;
	for (int i = 0; i < grid->heigth; i++)
		if (grid->grid[i])
			free(grid->grid[i]);
	if (grid->grid)
		free(grid->grid);
	grid->grid = NULL;
}

int cnt_line(char *line)
{
	int idx = 0;
	while (line[idx++] != '\0')
		continue ;
	return (idx);
}

char *ft_substr(char *line, int line_size)
{
	char *new_line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!new_line)
		return (NULL);
	for (int i = 0; i< line_size; i++)
		new_line[i] = line[i];
	new_line[line_size] = '\0';
	return new_line;
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

int fill_grid(FILE *fd, t_grid *grid, t_elements *elements)
{
	if (!grid || !elements)
		return (0);
	grid->grid = (char **)malloc(sizeof(char *) * grid->heigth);
	if (!grid->grid)
		return (0);
	for (int i = 0; i < grid->heigth; i++)
		grid->grid[i] = NULL;
	char *line = NULL;
	int b_read = 0;
	size_t len = 0;
	b_read = getline(&line, &len, fd);
	if (b_read == -1)
		return (free_grid(grid), 0);
	if (line)
		free(line);
	for (int i = 0; i < grid->heigth; i++)
	{
		line = NULL;
		len = 0;
		b_read = getline(&line, &len, fd);
		if (b_read == -1)
		{
			if (line)
				free(line);
			return (free_grid(grid), 0);
		}
		if (line[b_read - 1] == '\n')
			line[b_read -1] = '\0';
		int line_size = cnt_line(line);
		if (grid->width == 0)
			grid->width =  line_size;
		else
		{
			if (line_size != grid->width)
			{
				if (line)
					free(line);
				return (free_grid(grid), 0);
			}
		}
		grid->grid[i] = ft_substr(line, line_size);
		if (!grid->grid[i])
		{
			if (line)
					free(line);
				return (free_grid(grid), 0);
		}
		if (!verify_char(grid->grid[i], elements))
		{
			if (line)
				free(line);
			return (free_grid(grid), 0);
		}
		if (line)
			free(line);
	}
	return (1);
}

void free_grid_v2(int **tmp_board, int heigth)
{
	if (!tmp_board || !*tmp_board)
		return ;
	for (int i = 0; i < heigth; i++)
		if (tmp_board[i])
			free(tmp_board[i]);
	if (tmp_board)
		free(tmp_board);
	tmp_board = NULL;
}

int my_min(int x, int y, int z)
{
	if (x < y && x < z)
		return x;
	else if (y < z)
		return (y);
	else 
		return (z);
}

int bsq(t_grid *grid, t_elements *elements, t_square *square)
{
	if (!grid || !elements || !square)
		return (free_grid(grid), 0);
	int **tmp_grid = (int **)malloc(sizeof(int *) * grid->heigth);
	if (!tmp_grid)
		return (free_grid_v2(tmp_grid, grid->heigth), 0);
	for (int y = 0; y < grid->heigth; y++)
	{
		tmp_grid[y] = (int *)(malloc(sizeof(int) * grid->width));
		if (!tmp_grid[y])
			return (free_grid(grid), 0);
		for (int x = 0; x < grid->width; x++)
			tmp_grid[y][x] = 0;
	}
	for (int y = 0; y < grid->heigth; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if (grid->grid[y][x] == elements->obstacle)
				continue;
			else if(y == 0 || x == 0)
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
	if (tmp_grid)
		free_grid_v2(tmp_grid, grid->heigth);
	return (1);
}

int print_grid(t_grid *grid, t_elements *elements, t_square *square)
{
	if (!grid || !elements || !square)
		return (free_grid(grid), 0);
	for (int y = 0; y < grid->heigth; y++)
	{
		for (int x = 0; x < grid->width; x++)
		{
			if ((y >= square->y && y < (square->y + square->size)) && (x >= square->x && x < (square->x + square->size)))
				fprintf(stdout, "%c", elements->full);
			else
				fprintf(stdout, "%c", grid->grid[y][x]);
		}
		fprintf(stdout, "%c", '\n');
	}
	return (1);
}

int execute_bsq(FILE *file)
{
	if (!file)
		return (0);
	t_elements elements;
	if (!fill_elements(&elements, file))
		return (0);
	// printf ("number of lines: %d\n", elements.n_lines);
	// printf ("empty: %c\n", elements.empty);
	// printf ("obstacle: %c\n", elements.obstacle);
	// printf ("full: %c\n", elements.full);

	t_grid grid;
	grid.heigth = elements.n_lines;
	grid.width = 0;
	if (!fill_grid(file, &grid, &elements))
		return (0);

	// printf ("height: %d\n", grid.heigth);
	// printf ("width: %d\n\n", grid.width);

	// for (int y = 0; y < grid.heigth; y++)
	// {
	// 	for (int x = 0; x < grid.width; x++)
	// 		printf("%c", grid.grid[y][x]);
	// 	printf("\n");
	// }
	t_square square;
	square.x = 0;
	square.y = 0;
	square.size = 0;
	if (!bsq(&grid, &elements, &square))
		return (0);

	// printf("square size: %d\n", square.size);
	// printf("square x: %d\n", square.x);
	// printf("square y: %d\n", square.y);
	if(!print_grid(&grid, &elements, &square))
		return (0);
	free_grid(&grid);
	return (1);
}


int fileToPtr(char *argv)
{
	if (!argv)
		return (0);
	FILE *file = fopen(argv, "r");
	if (!file)
		return (0);
	execute_bsq(file);
	fclose(file);
	return (1);
}

int main(int argc, char **argv)
{
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
		for (int i = 1; i < argc; i++)
		{
			if (!fileToPtr(argv[i]))
			{
				fprintf(stderr, "map error\n");
				return (1);
			}
			fprintf(stdout, "%c", '\n');
		}
	}
	return (0);
}