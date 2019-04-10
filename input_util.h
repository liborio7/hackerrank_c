#ifndef FOO_INPUT_UTIL_H
#define FOO_INPUT_UTIL_H

#include <stdio.h>

int strtol_or_exit(char *);

char *read_line(FILE *file);

char **split_string(char *str, char *sep);

#endif