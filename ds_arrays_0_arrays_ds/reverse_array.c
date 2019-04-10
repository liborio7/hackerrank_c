#include "stdio.h"
#include "stdlib.h"
#include "../input_util.h"
#include "reverse_array.h"

int *new_reverse_array(int a_size, const int *a, int *res_size) {
    int *res = malloc((size_t) a_size);
    *res_size = a_size;

    int i_count = a_size / 2;
    for (int i = 0; i < i_count; ++i) {
        res[i] = a[a_size - 1 - i];
        res[a_size - 1 - i] = a[i];
    }
    if (a_size % 2 == 1) {
        res[i_count] = a[i_count];
    }

    return res;
}

int reverse_array(int a_size, int *a) {
    if (a_size < 0 || a == NULL) {
        return -1;
    }

    int temp;
    int i_count = a_size / 2;
    for (int i = 0; i < i_count; ++i) {
        temp = a[i];
        a[i] = a[a_size - 1 - i];
        a[a_size - 1 - i] = temp;
    }

    return 1;
}

int reverse_array_main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // read and convert first line containing input size
    char *arr_count_str = read_line(fp);
    int arr_count = strtol_or_exit(arr_count_str);

    // read and convert second line containing input items
    char **arr_items_str = split_string(read_line(fp), " ");
    int *arr = malloc(arr_count * sizeof(int));
    for (int i = 0; i < arr_count; i++) {
        arr[i] = strtol_or_exit(arr_items_str[i]);
    }

    // get result
    int res_count;
    int *res = new_reverse_array(arr_count, arr, &res_count);

    // print result
    for (int i = 0; i < res_count; i++) {
        printf("%d", res[i]);

        if (i != res_count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}