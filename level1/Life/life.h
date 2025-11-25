#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_game
{
	int	w;
	int	h;
	int iterations;
	int i;
	int j;
	int draw;
	char alive;
	char dead;
	char** board;
}	t_game;

void free_board(t_game* g);
int init_game(t_game* g, char** av);
void fill_board(t_game* g);
int countNeighbours(t_game* g, int i, int j);
int play(t_game* g);
void print_board(t_game* g);
