#include "pathfinder.h"

void mx_invalid_num_args(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
