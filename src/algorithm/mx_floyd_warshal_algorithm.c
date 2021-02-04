#include "pathfinder.h"

static void fill_fst_dist_mat(t_matrix *matrix, t_islands *isl) {
    matrix->fst_dist_mat = (long **)malloc(sizeof(long *) * isl->count_unique_isl);
    for (int h = 0; h < isl->count_unique_isl; h++) {
        matrix->fst_dist_mat[h] = (long *)malloc(sizeof(long) *
        isl->count_unique_isl);
    }
    for (int i = 0; i < isl->count_unique_isl; i++)
        for (int j = 0; j < isl->count_unique_isl; j++)
            matrix->fst_dist_mat[i][j] = matrix->adj_matrix[i][j];
}

void mx_floyd_warshal_algorithm(t_matrix *matrix, t_islands *isl) {
    fill_fst_dist_mat(matrix, isl);
    for (int k = 0; isl->unique_isl[k]; k++) {
        for (int i = 0; isl->unique_isl[i]; i++) {
            for (int j = 0; isl->unique_isl[j]; j++) {
                if (matrix->adj_matrix[i][j] > matrix->adj_matrix[i][k] +
                    matrix->adj_matrix[k][j]) {
                        matrix->adj_matrix[i][j] = matrix->adj_matrix[i][k] +
                        matrix->adj_matrix[k][j];
                        matrix->path_matrix[i][j] = k;
                }
            }
        }
    }
    for (int i = 0; i < isl->count_unique_isl; i++) {
        for (int j = 0; j < isl->count_unique_isl; j++) {
            if (i < j) {
                mx_result_output(matrix, isl, i, j);
            }
        }
    }
}
