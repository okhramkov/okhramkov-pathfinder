#include "libmx.h"

int mx_quicksort(int *arr, int left, int right);
int count = 0;
void mx_swap_int(int *xp, int *yp)
{
    count++;
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
static int count_move(int *arr, int *left, int *right, int *pos)
{
    int res = 0;
    if (*pos == *right)
        --(*right);
    if (*pos == *left)
        ++(*left);
    else {
        ++res;
        mx_swap_int(&arr[*pos], &arr[*left]);
    }
    if (*left < *right)
        res += mx_quicksort(arr, *left, *right);
    return res;
}
int mx_quicksort(int *arr, int left, int right) {
    if (!arr)
        return -1;
    int len = arr[left];
    int pos = left;
    for (int beg = left, end = right; beg < end; --end) {
        if (len > arr[end]) {
            pos = end;
            for (++beg; beg < end; ++beg) {
                if (len < arr[beg]) {
                    pos = beg;
                    break;
                }
            }
        }
    }
    return count_move(arr, &left, &right, &pos);
}
