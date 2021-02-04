#include "pathfinder.h"

void mx_path_matrix(t_matrix *matrix, t_islands *isl) {
    matrix->path_matrix = (int **)malloc(sizeof(int *) * isl->count_unique_isl);
    for (int h = 0; isl->unique_isl[h]; h++) {
        matrix->path_matrix[h] = (int *)malloc(sizeof(int) *
        isl->count_unique_isl);
    }
    for (int i = 0; i < isl->count_unique_isl; i++) {
        for (int j = 0; j < isl->count_unique_isl; j++)
            matrix->path_matrix[i][j] = j;
    }
}
