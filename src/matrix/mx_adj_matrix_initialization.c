#include "pathfinder.h"

void mx_adj_matrix_initialization(t_islands *isl, t_matrix *matrix) {
    matrix->adj_matrix = (long **)malloc(sizeof(long *) * isl->count_unique_isl);
    for (int h = 0; h < isl->count_unique_isl; h++) {
        matrix->adj_matrix[h] = (long *)malloc(sizeof(long) *
        isl->count_unique_isl);
    }
    for (int i = 0; i < isl->count_unique_isl; i++) {
        for (int j = 0; j < isl->count_unique_isl; j++) {
            matrix->adj_matrix[i][j] = INF;
            if (i == j)
                matrix->adj_matrix[i][j] = 0;
        }
    }
}
