#include "insert_head.h"
#include "stdio.h"
#include "stdlib.h"

linked_list_t *insert_node_at_head(linked_list_t *list, int data) {
    // allocate new node
    linked_list_node_t *head = malloc(sizeof(linked_list_node_t));
    head->data = data;

    if (list == NULL) {
        linked_list_t *new_list = malloc(sizeof(linked_list_t));
        new_list->head = head;
        new_list->size = 1;
        return new_list;
    }

    // update list and head next
    head->next = list->head;
    list->head = head;
    list->size++;

    return list;
}