#include "stdlib.h"
#include "stdio.h"
#include "hourglass.h"
#include "../input_util.h"

int max_hourglass(int arr_rows, int arr_columns, int **arr) {
    int max = -9 * 7;
    for (int row = 1; row < arr_rows - 1; ++row) {
        for (int col = 1; col < arr_columns - 1; ++col) {
            int sum = 0;
            sum += *(*(arr + row - 1) + col - 1);
            sum += *(*(arr + row - 1) + col);
            sum += *(*(arr + row - 1) + col + 1);
            sum += *(*(arr + row) + col);
            sum += *(*(arr + row + 1) + col - 1);
            sum += *(*(arr + row + 1) + col);
            sum += *(*(arr + row + 1) + col + 1);

            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

int max_hourglass_main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // init input matrix
    int row_count = 6;
    int col_count = 6;
    int **matrix = (int **) malloc(row_count * sizeof(int *));

    // read and convert input lines
    for (int i = 0; i < row_count; ++i) {
        char **arr_items_str = split_string(read_line(fp), " ");

        *(matrix + i) = (int *) malloc(col_count * sizeof(int));
        for (int j = 0; j < col_count; j++) {
            *(*(matrix + i) + j) = strtol_or_exit(arr_items_str[j]);
        }
    }

    // print matrix
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            printf("%d", *(*(matrix + i) + j));
            if (j != col_count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // get and print result
    int res = max_hourglass(row_count, col_count, matrix);
    printf("%d\n", res);

    return 0;
}