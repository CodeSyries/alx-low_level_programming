#include "custom_lists.h"

/**
 * insert_custom_node - inserts a new node at the beginning of a custom linked list
 * @custom_head: pointer to the first node in the custom list
 * @data: data to insert in the new node
 *
 * Returns: pointer to the new node, or NULL if insertion fails
 */
custom_node_t *insert_custom_node(custom_node_t **custom_head, const int data)
{
    custom_node_t *new_node;

    new_node = malloc(sizeof(custom_node_t));
    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = *custom_head;
    *custom_head = new_node;

    return new_node;
}
