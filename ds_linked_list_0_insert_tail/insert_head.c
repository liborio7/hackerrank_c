#include "insert_tail.h"
#include "stdlib.h"
#include "stdio.h"
#include "../input_util.h"

linked_list_t *insert_node_at_tail(linked_list_t *list, int data) {
    // allocate new node
    linked_list_node_t *tail = malloc(sizeof(linked_list_node_t));
    tail->data = data;
    tail->next = NULL;

    if (list == NULL) {
        linked_list_t *new_list = malloc(sizeof(linked_list_t));
        new_list->head = tail;
        new_list->size = 1;
        return new_list;
    }

    // traverse linked list and update tail
    linked_list_node_t *tmp_node = list->head;
    while (tmp_node->next != NULL) {
        tmp_node = tmp_node->next;
    }
    tmp_node->next = tail;
    list->size++;

    return list;
}

int insert_node_at_tail_main() {
    // open input file
    FILE *fp = fopen("../input", "r");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(EXIT_FAILURE);
    }

    // read size
    char *sizes = read_line(fp);
    int list_size = strtol_or_exit(sizes);

    // read and convert data
    linked_list_t *list = NULL;
    for (int i = 0; i < list_size; ++i) {
        char *data_str = read_line(fp);
        int data = strtol_or_exit(data_str);

        list = insert_node_at_tail(list, data);
    }

    // result
    print_linked_list(list);

    return 0;
}