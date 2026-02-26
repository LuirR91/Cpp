#include "bsq.h"
typedef struct
{
	int		rows;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
	int		cols;
}	map;

typedef struct
{
	int	size;
	int	row;
	int col;
}	square;


int	min(int a, int b, int c)
{
	int	m = a < b ? a : b;
	return m < c ? m : c;
}

void	free_map(map *map)
{
	if (map->grid)
	{
		for (int i = 0; i < map->rows; i++)
			free(map->grid[i]);
		free(map->grid);
	}
}

int	valid_char(char c)
{
	return (c >= 32 && c <= 126);
}

int	parse_header(FILE *f, map *map)
{
	if (fscanf(f, "%d %c %c %c\n", &map->rows, &map->empty, &map->obstacle, &map->full) != 4)
		return 0;
	if (!valid_char(map->obstacle) || !valid_char(map->empty) || !valid_char(map->full))
		return 0;
	if (map->rows <= 0 || map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
		return 0;
	return 1;
}

int	read_map(FILE *f, map *map)
{
	map->grid = NULL;
	map->cols = 0;

	if (!parse_header(f, map))
		return 0;
	
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return 0;
	
	for (int i = 0; i < map->rows; i++)
		map->grid[i] = NULL;
	
	char *line = NULL;
	size_t len = 0;

	for (int i = 0; i < map->rows; i++)
	{
		ssize_t read = getline(&line, &len, f);
		if (read <= 0)
		{
			free(line);
			return 0;
		}

		if (line[read - 1] == '\n')
			line[--read] = '\0';
		
		if (i == 0)
			map->cols = read;
		else if (read != map->cols)
		{
			free(line);
			return 0;
		}

		if (map->cols <= 0)
		{
			free(line);
			return 0;
		}

		map->grid[i] = malloc(map->cols + 1);
		if (!map->grid[i])
		{
			free(line);
			return 0;
		}

		for (int j = 0; j < map->cols; j++)
		{
			if (line[j] != map->empty && line[j] != map->obstacle)
			{
				free(line);
				return 0;
			}
			map->grid[i][j] = line[j];
		}
		map->grid[i][map->cols] = '\0';
	}
	free(line);
	return 1;
}


square	find_biggest_square(map *map)
{
	square	best = {0 , 0 , 0};

	int	**dp = malloc(sizeof(int *) * map->rows);

	if (!dp)
		return best;
	
	for (int i = 0; i < map->rows; i++)
	{
		dp[i] = calloc(map->cols, sizeof(int));
		if (!dp[i])
		{
			for (int j = 0; j < i; j++)
				free(dp[j]);
			free(dp);
			return best;
		}
	}

	for (int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->cols; j++)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = min(dp[i - 1][j], dp[i][j-1], dp[i-1][j-1]) + 1;

			if (dp[i][j] > best.size)
			{
				best.size = dp[i][j];
				best.row = i - dp[i][j] + 1;
				best.col = j - dp[i][j] + 1;
			}
		}
	}

	for (int i = 0; i < map->rows; i++)
		free(dp[i]);
	free(dp);
	return best;
}

void	fill_square(map *map, square sq)
{
	for (int i = sq.row; i < sq.row + sq.size; i++)
	{
		for (int j = sq.col; j < sq.col + sq.size; j++)
			map->grid[i][j] = map->full;
	}
}

void	print_map(map *map)
{
	for (int i = 0; i < map->rows; i++)
		fprintf(stdout, "%s\n", map->grid[i]);
}


void	process_file(FILE *f)
{
	map map = {0};

	if (!read_map(f, &map))
	{
		fprintf(stderr, "map error\n");
		free_map(&map);
		return ;
	}

	square sq = find_biggest_square(&map);
	fill_square(&map, sq);
	print_map(&map);
	free_map(&map);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		process_file(stdin);
	else
	{
		for (int i = 1; i < argc; i++)
		{
			FILE *f = fopen(argv[i], "r");
			if (!f)
			{
				fprintf(stderr, "map error\n");
				continue;
			}
			process_file(f);
			fclose(f);
			if (i < argc - 1)
				printf("\n");
		}
	}
	return 0;
}

