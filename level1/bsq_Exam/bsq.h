#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map {
    size_t rows;
    size_t cols;
    char empty_c;
    char obst_c;
    char full_c;
    char **grid;
} t_map;

int execute_bsq(FILE *f);
int convert_file_pointer(char *path);