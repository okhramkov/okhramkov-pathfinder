#include "pathfinder.h"

void mx_same_island_in_line(t_islands *isl, int *line_count) {
    *line_count = 2;

    for (int i = 0; i <= isl->count_words - 3; i += 3) {
        if (mx_strcmp(isl->isl_dist[i], isl->isl_dist[i + 1]) == 0)
            mx_output_invalid_line_number(line_count);
        (*line_count)++;
    }
}
