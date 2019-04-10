#include "dynamic_array.h"
#include "stdio.h"
#include "stdlib.h"
#include "../output_util.h"
#include "../input_util.h"

typedef struct {
    int size;
    int *arr;
} seq_t;

void query_1(seq_t *seq, int y) {
    seq->arr = reallocf(seq->arr, ++seq->size * sizeof(int));
    if (seq->arr == NULL) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    seq->arr[seq->size - 1] = y;
}

int query_2(seq_t *seq, int y) {
    return seq->arr[y % seq->size];
}

int *dynamic_array(int seq_size, int queries_rows, int **queries, int *result_size) {
    // initialize result
    int *result = NULL;
    *result_size = 0;

    // initialize seq array and last answer
    seq_t **seqs = malloc(seq_size * sizeof(seq_t *));
    for (int i = 0; i < seq_size; ++i) {
        seqs[i] = malloc(sizeof(seq_t));
        seqs[i]->size = 0;
        seqs[i]->arr = NULL;
    }
    int last_answer = 0;

    for (int i = 0; i < queries_rows; ++i) {
        int *query = queries[i];
        int x = query[1];
        int y = query[2];

        seq_t *seq = seqs[(x ^ last_answer) % seq_size];
        if (query[0] == 1) {
            query_1(seq, y);

        } else if (query[0] == 2) {
            last_answer = query_2(seq, y);

            result = reallocf(result, ++(*result_size) * sizeof(int));
            if (result == NULL) {
                printf("Error allocating memory!\n");
                exit(EXIT_FAILURE);
            }

            result[*result_size - 1] = last_answer;

        } else {
            printf("query not implemented");
            exit(EXIT_FAILURE);
        }
    }
    return result;
}

int dynamic_array_main() {
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
    int result_size;
    int *result = dynamic_array(arr_size, queries_size, queries, &result_size);

    print_int_array(result, result_size);

    return 0;
}