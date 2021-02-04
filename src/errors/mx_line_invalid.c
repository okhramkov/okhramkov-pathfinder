#include "pathfinder.h"

static void check_island_dist_exist(int *line_count, char *str) {
    int i;
    int digit;

    for (i = 0; str[i] != '\n'; i++) { //check whether both islands exist
        if (str[i] == '-' && (!mx_isalpha(str[i - 1]) || !mx_isalpha(str[i + 1])))
            mx_output_invalid_line_number(line_count);
    }
    for (i = 0; str[i] != '\n'; i++) { //check whether distance exists
        if (str[i] == ',' && (!mx_isalpha(str[i - 1]) || !mx_isdigit(str[i + 1])))
            mx_output_invalid_line_number(line_count);
    }
}

void mx_line_invalid(int *line_count, char *str) {
    int i;

    if (*str != '\0') {
        if (str[0] == '\n')
            mx_output_invalid_line_number(line_count);
        check_island_dist_exist(line_count, str);
        for (i = 0; str[i] != '-'; i++) {
            if (!mx_isalpha(str[i]))
                mx_output_invalid_line_number(line_count);
        }
        for (i += 1; str[i] != ','; i++) {
            if (!mx_isalpha(str[i]))
                mx_output_invalid_line_number(line_count);
        }
        for (i += 1; str[i] != '\n'; i++) {
            if (!mx_isdigit(str[i]))
                mx_output_invalid_line_number(line_count);
        }
    (*line_count) += 1;
    i += 1;
    mx_line_invalid(line_count, str + i);
    }
}
