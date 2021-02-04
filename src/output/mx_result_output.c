#include "pathfinder.h"

static int* mem_int_arr(int count) {
	int *arr = (int*)malloc(sizeof(int) * count);
	int j = 0;

	for(; j < count; j++)
		arr[j] = 0;
	return arr;
}

static t_backpath *new_route(t_islands *isl, int start, int finish) {
	t_backpath *bp = (t_backpath*)malloc(sizeof(t_backpath));
    int len = isl->count_unique_isl;

	if(bp == NULL)
		exit(-1);
	bp->route = mem_int_arr(len);
	bp->size = 1;
	bp->count = len;
	bp->route[0] = finish;
	bp->route[1] = start;
	return bp;
}

void mx_result_output(t_matrix *matrix, t_islands *isl, int i, int j) {
    t_backpath *bp = new_route(isl, i, j);
    mx_floyd_backtrack(matrix, isl, bp);
    free(bp->route);
    free(bp);
}
