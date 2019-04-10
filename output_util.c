#include "output_util.h"
#include "stdio.h"

void print_string_array(char **arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%s", arr[i]);

        if (i != arr_size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_int_array(int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);

        if (i != arr_size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_int_matrix(int **m, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d", *(*(m + i) + j));

            if (j != cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}