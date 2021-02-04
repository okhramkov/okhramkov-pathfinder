#include "pathfinder.h"

void mx_output_invalid_line_number(int *line_count) {
    char *count;

    count = mx_itoa((int)(*line_count));
    mx_printerr("error: line ");
    mx_printerr(count);
    mx_printerr(" is not valid\n");
    if (count)
        free(count);
    exit(1);
}
