#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#define INF 2147483647

typedef struct s_backpath {
    int *route;
    int size;
    int count;
} t_backpath;

typedef struct s_islands {
    char **isl_dist;
    char **unique_isl;
    int digit;
    int count_words;
    int count_unique_isl;
    long sum_dist;
} t_islands;

typedef struct s_matrix {
    long **fst_dist_mat;
    long **adj_matrix;
    int **path_matrix;
    int *dist_path;
} t_matrix;

//---error_handling_pack---
void mx_handling(int argc, char **argv, t_islands *isl,
                        t_matrix *matrix);

void mx_invalid_num_args(int argc);
void mx_file_exists(char *argv);
void mx_file_empty(char *argv);
char *mx_line1_not_digit(int *line_count, char *str, t_islands *isl);
void mx_line_invalid(int *line_count, char *str);
void mx_output_invalid_line_number(int *line_count);
void mx_invalid_num_islands(t_islands *isl, char *str);
void mx_same_island_in_line(t_islands *isl, int *line_count);
void mx_duplicate_bridges(t_islands *isl);
void mx_clean_struct(t_islands *isl, t_matrix *matrix);
void mx_bridge_length(t_islands *isl);

//---matrix initialization---
void mx_adj_matrix_initialization(t_islands *isl, t_matrix *matrix);
void mx_adjacency_matrix(t_islands *isl, t_matrix *matrix);
void mx_path_matrix(t_matrix *matrix, t_islands *isl);

//---algorithm---
void mx_floyd_warshal_algorithm(t_matrix *matrix, t_islands *isl);

//---result output---
void mx_result_output(t_matrix *matrix, t_islands *isl, int i, int j);
void mx_print_boundary();
void mx_buff_print(t_islands *isl, t_backpath *bp);

//---backtracking---
void mx_floyd_backtrack(t_matrix *matrix, t_islands *isl, t_backpath *bp);
#endif
