#include "pathfinder.h"

static int get_isl_index(char *island, t_islands *isl) {
    for (int j = 0; isl->unique_isl[j]; j++)
        if (mx_strcmp(island, isl->unique_isl[j]) == 0)
            return j;
    return 0;
}

void mx_adjacency_matrix(t_islands *isl, t_matrix *matrix) {
    int row;
    int col;

    for (int i = 0; isl->isl_dist[i]; i += 3) {
        row = get_isl_index(isl->isl_dist[i], isl);
        col = get_isl_index(isl->isl_dist[i + 1], isl);
        matrix->adj_matrix[row][col] = mx_atoi(isl->isl_dist[i + 2]);
        matrix->adj_matrix[col][row] = matrix->adj_matrix[row][col];
    }
}
