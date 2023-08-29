#ifndef CUSTOM_LISTS_H
#define CUSTOM_LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * node_s - singly linked node
 * @data: integer data
 * @next: points to the next node
 *
 * Description: structure for singly linked nodes
 * used in a custom project
 */
typedef struct node_s
{
    int data;
    struct node_s *next;
} custom_node_t;

size_t custom_print_data(const custom_node_t *ptr);
size_t custom_data_count(const custom_node_t *ptr);
custom_node_t *custom_add_data(custom_node_t **head, const int data);
custom_node_t *custom_append_data(custom_node_t **head, const int data);
void custom_free_data(custom_node_t *head);
void custom_free_data2(custom_node_t **head);
int custom_pop_data(custom_node_t **head);
custom_node_t *custom_get_data_at_index(custom_node_t *head, unsigned int index);
int custom_sum_data(custom_node_t *head);
custom_node_t *custom_insert_data_at_index(custom_node_t **head, unsigned int idx, int data);
int custom_delete_data_at_index(custom_node_t **head, unsigned int index);
custom_node_t *custom_reverse_data(custom_node_t **head);
size_t custom_print_data_safely(const custom_node_t *head);
size_t custom_free_data_safely(custom_node_t **h);
custom_node_t *custom_find_data_loop(custom_node_t *head);

#endif
