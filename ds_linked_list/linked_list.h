#ifndef PLAYGROUND_LINKED_LIST_H
#define PLAYGROUND_LINKED_LIST_H

typedef struct linked_list_t linked_list_t;
typedef struct linked_list_node_t linked_list_node_t;

struct linked_list_t {
    struct linked_list_node_t *head;
    int size;
};

struct linked_list_node_t {
    int data;
    linked_list_node_t *next;
};

void print_linked_list(linked_list_t *list);

#endif
