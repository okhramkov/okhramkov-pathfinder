#include "pathfinder.h"

int main(int argc, char *argv[]) {
	t_islands *isl = (t_islands*)malloc(sizeof(t_islands));
	t_matrix *matrix = (t_matrix*)malloc(sizeof(t_matrix));

	mx_handling(argc, argv, isl, matrix);
	mx_adj_matrix_initialization(isl, matrix);
	mx_adjacency_matrix(isl, matrix);
	mx_path_matrix(matrix, isl);
	mx_floyd_warshal_algorithm(matrix, isl);
	mx_clean_struct(isl, matrix);
	return 0;
}
