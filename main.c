#include "stdio.h"
#include "stdlib.h"
#include "input_util.h"
#include "output_util.h"
#include "ds_linked_list_0_insert_tail/insert_tail.h"
#include "ds_linked_list_2_insert_position/insert_position.h"

int main1() {
    printf("%d\n", 1 % 10);

    return 0;
}

int main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // read size
    char *sizes = read_line(fp);
    int list_size = strtol_or_exit(sizes);

    // read and convert initial data
    linked_list_t *list = NULL;
    for (int i = 0; i < list_size; ++i) {
        char *data_str = read_line(fp);
        int data = strtol_or_exit(data_str);

        list = insert_node_at_tail(list, data);
    }

    // read and convert data to insert
    while (!feof(fp)) {
        int data = strtol_or_exit(read_line(fp));
        int position = strtol_or_exit(read_line(fp));

        list = insert_node_at(list, data, position);
    }

    // print result
    print_linked_list(list);

    return 0;
}