#include "pathfinder.h"

static void del_long_arr(long **arr, int len) {
    if (arr) {
        for (int i = 0; i < len; i++)
            free(arr[i]);
        free(arr);
    }
}

void mx_clean_struct(t_islands *isl, t_matrix *matrix) {
    if (isl->isl_dist)
        mx_del_strarr(&isl->isl_dist);
    if (isl->unique_isl)
        mx_del_strarr(&isl->unique_isl);
    if (matrix->fst_dist_mat)
        del_long_arr(matrix->fst_dist_mat, isl->count_unique_isl);
    if (matrix->adj_matrix)
        del_long_arr(matrix->adj_matrix, isl->count_unique_isl);
    if (matrix->path_matrix)
        mx_del_intarr(matrix->path_matrix, isl->count_unique_isl);
    if (isl)
        free(isl);
    if (matrix)
        free(matrix);
}
