#include "input_util.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
 * str to long converter; exit on failure
 */
int strtol_or_exit(char *str) {
    // convert str to long
    char *endptr;
    int arr_count = (int) strtol(str, &endptr, 10);

    // check endptr
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);

    } else {
        return arr_count;
    }
}

/*
 * read input from sdtin and return a char pointer
 */
char *read_line(FILE *file) {
    // alloc memory
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = (char *) malloc(alloc_length);

    // read
    while (1) {
        // update cursor pointer and call fgets on it
        char *cursor = data + data_length;
        char *line = fgets(cursor, (int) (alloc_length - data_length), file);

        // end read when no new line is found
        if (!line) {
            break;
        }

        // update data length
        data_length += strlen(cursor);

        // end read when end of line is found
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        // update alloc length (x2) and reallocate data
        alloc_length <<= 1;
        data = (char *) realloc(data, alloc_length);
    }

    // force '\0' to be at the end of data, reallocating memory if needed
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = (char *) realloc(data, data_length);

    } else {
        data = (char *) realloc(data, data_length + 1);
        data[data_length] = '\0';
    }

    return data;
}

/*
 * split a string by a given separator into a string array
 */
char **split_string(char *str, char *sep) {
    // get the first token of str argument
    char **splits = NULL;
    char *token = strtok(str, sep);

    // walk through other tokens
    int n_tokens = 0;
    while (token) {
        // realloc splits by 1
        splits = (char **) realloc(splits, sizeof(char *) * ++n_tokens);

        // break on realloc failure
        if (!splits) {
            return splits;
        }

        // put current token at the end of the splits array
        splits[n_tokens - 1] = token;

        // read next token
        token = strtok(NULL, sep);
    }

    return splits;
}

