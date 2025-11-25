#include "life.h"

void free_board(t_game* g)
{
	if (g->board)
	{
		for (int i = 0; i < g->h; i++)
			if (g->board[i])
				free(g->board[i]);
		free(g->board);
	}
	g->board = NULL;
}

int init_game(t_game* g, char** av)
{
	g->w = atoi(av[1]);
	g->h = atoi(av[2]);
	g->iterations = atoi(av[3]);
	g->i = 0;
	g->j = 0;
	g->draw = 0;
	g->alive = '0';
	g->dead = ' ';
	g->board = calloc((g->h + 1), sizeof(char *));

	if (!g->board)
		return -1;
	for (int i = 0; i < g->h; i++)
	{
		g->board[i] = calloc((g->w + 1), sizeof(char *));
		if (!g->board[i])
		{
			free_board(g);
			return -1;
		}
		for (int j = 0; j < g->w; j++)
			g->board[i][j] = g->dead;
	}
	return 0;
}

void fill_board(t_game* g)
{
	char buffer;
	int flag = 0;

	while (read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch (buffer)
		{
			case 'w':
				if (g->i > 0)
					g->i--;
				break;
			case 's':
				if (g->i < g->h)
					g->i++;
				break;
			case 'a':
				if (g->j > 0)
					g->j--;
				break;
			case 'd':
				if (g->j < g->w)
					g->j++;
				break;
			case 'x':
				g->draw = !(g->draw);
				break;
			default:
				flag = 1;
				break;
		}
		if (g->draw && (flag == 0))
			if ((g->i >= 0) && (g->i < g->h) && (g->j >= 0) && (g->j < g->w))
				g->board[g->i][g->j] = g->alive;
	}
}

int countNeighbours(t_game* g, int i, int j)
{
	int count = 0;
	for (int ii = -1; ii <= 1; ii++)
	{
		for (int jj = -1; jj <= 1; jj++)
		{
			if (ii == 0 && jj == 0)
				continue;
			int ni = i + ii;
			int nj = j + jj;
			if ((ni >= 0) && (nj >= 0) && (ni < g->h) && (nj < g->w))
				if (g->board[ni][nj] == g->alive)
					count++;
		}
	}
	return count;
}

int play(t_game* g)
{
	char** newBoard = calloc((g->h + 1), sizeof(char *));
	if (!newBoard)
		return -1;
	for (int i = 0; i < g->h; i++)
	{
		newBoard[i] = calloc((g->w + 1), sizeof(char *));
		if (!newBoard)
		{
			newBoard[i] = NULL;
			return -1;
		}
	}

	for (int i = 0; i < g->h; i++)
	{
		for (int j = 0; j < g->w; j++)
		{
			int neighbours = countNeighbours(g, i, j);
			if (g->board[i][j] == g->alive)
			{
				if (neighbours == 2 || neighbours == 3)
					newBoard[i][j] = g->alive;
				else
					newBoard[i][j] = g->dead;
			}
			else
			{
				if (neighbours == 3)
					newBoard[i][j] = g->alive;
				else
					newBoard[i][j] = g->dead;
			}
		}
	}

	free_board(g);
	g->board = newBoard;
	return 0;
}

void print_board(t_game* g)
{
	for (int i = 0; i < g->h; i++)
	{
		for (int j = 0; j < g->w; j++)
			putchar(g->board[i][j]);
		putchar('\n');
	}
}

int main (int ac, char** av)
{
	if (ac != 4)
		return 1;
	
	t_game g;

	if (init_game(&g, av) == -1)
		return 1;
	
	fill_board(&g);

	for (int i = 0; i < g.iterations; i++)
	{
		if (play(&g) == -1)
		{
			free_board(&g);
			return -1;
		}
	}
	print_board(&g);
	if (g.board)
		free_board(&g);
	return 0;
}

