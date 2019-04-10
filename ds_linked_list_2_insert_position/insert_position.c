#include "insert_position.h"
#include "stdlib.h"
#include "stdio.h"
#include "../input_util.h"
#include "../ds_linked_list_0_insert_tail/insert_tail.h"

linked_list_t *insert_node_at(linked_list_t *list, int data, int position) {
    // traverse linked list until position
    linked_list_node_t *prev_node = NULL;
    linked_list_node_t *current_node = list->head;
    for (int i = 0; i < position; ++i) {
        prev_node = current_node;
        current_node = current_node->next;

        if (current_node == NULL) {
            printf("out of bound\n");
            exit(EXIT_FAILURE);
        }
    }

    // allocate new node
    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
    node->data = data;

    // update nodes
    if (prev_node != NULL) {
        prev_node->next = node;
    }
    node->next = current_node;

    return list;
}

int insert_node_at_main() {
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