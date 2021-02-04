#include "pathfinder.h"

void mx_handling(int argc, char **argv, t_islands *isl,
                        t_matrix *matrix) {
    int line_count = 1;
    char *str = NULL;
    char *head = NULL;

    mx_invalid_num_args(argc);
    mx_file_exists(argv[1]);
    mx_file_empty(argv[1]);
    str = mx_file_to_str(argv[1]);
    head = str;
    str = mx_line1_not_digit(&line_count, str, isl);
    mx_line_invalid(&line_count, str);
    str = head;
    mx_invalid_num_islands(isl, str);
    if (str)
        free(str);
    mx_same_island_in_line(isl, &line_count);
    mx_duplicate_bridges(isl);
    mx_bridge_length(isl);
}
