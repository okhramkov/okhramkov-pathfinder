#include "pathfinder.h"

static int check_shortest(int n, t_matrix *matrix, t_backpath *bp) {
	int i = bp->route[bp->size];
	int j = bp->route[0];

	if (i != n) {
		if (matrix->fst_dist_mat[i][n] == matrix->adj_matrix[j][i] -
            matrix->adj_matrix[j][n])
			return 1;
	}
	return 0;
}

static void print_route(t_islands *isl, t_backpath *bp) {
	mx_printstr("Route: ");
	for (int i = 1; i <= bp->size; i++) {
		mx_printstr(isl->unique_isl[bp->route[i]]);
		if (i < bp->size)
			mx_printstr(" -> ");
		else {
			mx_printstr("\n");
			mx_printstr("Distance: ");
		}
	}
}

static void print_buffer_path(t_matrix *matrix, t_backpath *bp, int sum) {
	for (int i = 1; i < bp->size; i++){
		mx_printint(matrix->fst_dist_mat[bp->route[i]][bp->route[i + 1]]);
		sum += matrix->fst_dist_mat[bp->route[i]][bp->route[i + 1]];
		if (i < bp->size - 1)
			mx_printstr(" + ");
		else if (i != 1){
			mx_printstr(" = ");
			mx_printint(sum);
		}
	}
}

void mx_floyd_backtrack(t_matrix *matrix, t_islands *isl, t_backpath *bp) {
    int len = isl->count_unique_isl;
	int sum = 0;

	if (bp->route[bp->size] == bp->route[0]) {
		mx_buff_print(isl, bp);
    	print_route(isl, bp);
		print_buffer_path(matrix, bp, sum);
			mx_printstr("\n");
		mx_print_boundary();
	}
	else {
		for (int i = 0; i < len; i++)
			if(check_shortest(i, matrix, bp)) {
				if (bp->size < bp->count) {
					bp->size++;
					bp->route[bp->size] = i;
				}
				mx_floyd_backtrack(matrix, isl, bp);
				if(bp->size > 1)
					bp->size--;
			}
	}
}
