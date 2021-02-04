#include "pathfinder.h"

void mx_file_exists(char *str) {
    int file;

    file = open(str, O_RDONLY);
	if (file < 0) {
        mx_printerr("error: file ");
        mx_printerr(str);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    close(file);
}
