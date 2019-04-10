#include "stdbool.h"
#include "rotate.h"
#include "stdio.h"
#include "stdlib.h"
#include "../debug_util.h"
#include "../output_util.h"
#include "../input_util.h"

int *new_rotate_left(int a_count, const int *a, int n) {
    int *res = malloc(a_count * sizeof(int));
    for (int i = 0; i < a_count; ++i) {
        res[(i + a_count - n) % a_count] = a[i];
    }
    return res;
}

int rotate_left(int a_count, int *a, int n) {
    if (a_count < 0 || a == NULL) {
        return -1;
    }
    if (a_count == 0 || n == 0) {
        return 1;
    }

    // prevent from switching always same positions if array size is divisible by n
    int div = a_count % n ? a_count : a_count / n;

    // init position and item to switch
    int pos = 0;
    int current = a[pos];
    int temp;
    for (int i = 0; i < a_count; ++i) {
        // calculate new position
        int new_pos = (pos + a_count - n) % a_count;

        // switch current item with the item in the new position
        temp = a[new_pos];
        a[new_pos] = current;
        current = temp;

        // update position
        pos = new_pos;

        // re-calculate position if necessary
        if ((i + 1) % div == 0) {
            current = a[++pos];
        }
    }

    return 0;
}

int rotate_main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // read and convert first line containing input size
    char **arr_count_str = split_string(read_line(fp), " ");
    int arr_count = strtol_or_exit(arr_count_str[0]);
    int n = strtol_or_exit(arr_count_str[1]);

    // read and convert second line containing input items
    char **arr_items_str = split_string(read_line(fp), " ");
    int *arr = malloc(arr_count * sizeof(int));
    for (int i = 0; i < arr_count; i++) {
        arr[i] = strtol_or_exit(arr_items_str[i]);
    }

    // get result
    int res = rotate_left(arr_count, arr, n);
    if (res < 0) {
        printf("rotate left error\n");
        exit(EXIT_FAILURE);
    }

    print_int_array(arr, arr_count);

    return 0;
}