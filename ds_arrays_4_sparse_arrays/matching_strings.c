#include "matching_strings.h"
#include "stdio.h"
#include "stdlib.h"
#include "../debug_util.h"
#include "../input_util.h"
#include "../output_util.h"

int match_string(const char *string, const char *query) {
    for (int i = 0; i < MAX_STRING_SIZE; ++i) {
        char s_ch = *(string + i);
        char q_ch = *(query + i);
        if (s_ch != q_ch) {
            return 0;
        }
        if (s_ch == '\0' && q_ch == '\0') {
            return 1;
        }
    }
    return 1;
}

int *matching_strings(int strings_size, char **strings, int queries_size, char **queries,
                      int *result_size) {
    int *result = (int *) malloc(queries_size * sizeof(int));
    *result_size = queries_size;

    for (int i = 0; i < queries_size; ++i) {
        int sum = 0;
        char *query = *(queries + i);

        for (int j = 0; j < strings_size; ++j) {
            char *string = *(strings + j);
            sum += match_string(string, query);
        }

        *(result + i) = sum;
    }

    return result;
}

int matching_strings_main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // read and convert strings
    int strings_size = strtol_or_exit(read_line(fp));
    char **strings = malloc(strings_size * sizeof(char *));
    for (int i = 0; i < strings_size; ++i) {
        *(strings + i) = read_line(fp);
    }

    // read and convert queries
    int queries_size = strtol_or_exit(read_line(fp));
    char **queries = malloc(queries_size * sizeof(char *));
    for (int i = 0; i < queries_size; ++i) {
        *(queries + i) = read_line(fp);
    }

    // get result
    int result_size = 0;
    int *result = matching_strings(strings_size, strings, queries_size, queries, &result_size);

    print_int_array(result, result_size);

    return 0;
}