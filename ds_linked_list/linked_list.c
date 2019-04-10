#include "linked_list.h"
#include "stdio.h"
#include "stdlib.h"

void print_linked_list(linked_list_t *list) {
    linked_list_node_t *tmp_node = list->head;
    while (tmp_node != NULL) {
        printf("%d\n", tmp_node->data);

        tmp_node = tmp_node->next;
    }
}