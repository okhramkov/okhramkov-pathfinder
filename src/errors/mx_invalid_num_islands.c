#include "pathfinder.h"

static void sorted_islands_array(t_islands *isl) {
    isl->count_unique_isl = 1;
    isl->unique_isl = (char **)malloc(sizeof(char *) * isl->count_words);
    isl->unique_isl[0] = mx_strdup(isl->isl_dist[0]);
    isl->unique_isl[1] = NULL;

    if (isl->unique_isl[0]) {
        for (int i = 1; isl->isl_dist[i]; i++) {
            if (mx_isdigit(isl->isl_dist[i][0]))
                continue;
            for (int j = 0; isl->unique_isl[j]; j++) {
                if (mx_strcmp(isl->isl_dist[i], isl->unique_isl[j]) == 0)
                    break;
                if (mx_strcmp(isl->isl_dist[i], isl->unique_isl[j]) != 0 &&
                    isl->unique_isl[j + 1] == NULL) {
                    isl->unique_isl[j + 1] = mx_strdup(isl->isl_dist[i]);
                    isl->unique_isl[j + 2] = NULL;
                    isl->count_unique_isl += 1;
                }
            }
        }
    }
}

void mx_invalid_num_islands(t_islands *isl, char *str) {
    int i;

    if (*str != '\0') {
        for (i = 0; str[i] != '\n'; i++) {
            if (mx_isdigit(str[i]))
                isl->digit = mx_atoi(str);
        }
        str += mx_intlen(isl->digit);
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == '-' || str[i] == ',' || str[i] == '\n')
                str[i] = ' ';
        }
        isl->count_words = mx_count_words(str, ' ');
        isl->isl_dist = mx_strsplit(str, ' ');
        sorted_islands_array(isl);
    }
    if (isl->count_unique_isl == 1 && isl->digit == 0)
        exit(0);
    if (isl->count_unique_isl != isl->digit) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
