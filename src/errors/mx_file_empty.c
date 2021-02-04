#include "pathfinder.h"

void mx_file_empty(char *argv) {
    int file;
    int file_length = 0;
    char buffer[1];

    file = open(argv, O_RDONLY);
    for (;read(file, buffer, 1); file_length++);
    if (file_length <= 0) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" is empty\n");
        close(file);
        exit(1);
    }
}
