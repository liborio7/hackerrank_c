#include "stdio.h"
#include "debug_util.h"

void print_char_var(const char *name, char var) {
    printf("%s: %c\n", name, var);
}

void print_string_var(const char *name, const char *var) {
    printf("%s: %s\n", name, var);
}

void print_int_var(const char *name, int var) {
    printf("%s: %d\n", name, var);
}
