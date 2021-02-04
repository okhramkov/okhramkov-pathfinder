#include "pathfinder.h"

void mx_bridge_length(t_islands *isl) {
    isl->sum_dist = 0;

    for (int i = 2; i <= isl->count_words - 1; i += 3) {
        isl->sum_dist += mx_atoi(isl->isl_dist[i]);
    }
    if (isl->sum_dist > 2147483647) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}
