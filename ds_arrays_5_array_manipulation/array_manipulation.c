#include "array_manipulation.h"
#include "stdio.h"
#include "stdlib.h"
#include "../debug_util.h"
#include "../input_util.h"

long array_manipulation(int arr_size, int queries_rows, int **queries) {
    int *arr = calloc((size_t) arr_size, sizeof(int));
    for (int i = 0; i < queries_rows; ++i) {
        int from = *(*(queries + i));
        int to = *(*(queries + i) + 1);
        int value = *(*(queries + i) + 2);

        arr[from - 1] += value;
        if (to < arr_size) {
            arr[to] -= value;
        }
    }
    long max_sum = 0;
    long sum = 0;
    for (int i = 0; i < arr_size; ++i) {
        sum += arr[i];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}

int array_manipulation_main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // read and convert sizes
    char **sizes = split_string(read_line(fp), " ");
    int arr_size = strtol_or_exit(*(sizes));
    int queries_size = strtol_or_exit(*(sizes + 1));

    // read and convert queries
    int **queries = malloc(queries_size * sizeof(int *));
    for (int i = 0; i < queries_size; ++i) {
        char **query_row = split_string(read_line(fp), " ");

        int *query = malloc(3 * sizeof(int));
        *(query) = strtol_or_exit(*(query_row));
        *(query + 1) = strtol_or_exit(*(query_row + 1));
        *(query + 2) = strtol_or_exit(*(query_row + 2));

        *(queries + i) = query;
    }

    // result
    long result = array_manipulation(arr_size, queries_size, queries);

    printf("%ld\n", result);

    return 0;
}