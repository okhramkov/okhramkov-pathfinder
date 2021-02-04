#include "pathfinder.h"

void mx_buff_print(t_islands *isl, t_backpath *bp) {
		mx_print_boundary();
		mx_printstr("Path: ");
		mx_printstr(isl->unique_isl[bp->route[1]]);
    	mx_printstr(" -> ");
    	mx_printstr(isl->unique_isl[bp->route[0]]);
    	mx_printstr("\n");
}
