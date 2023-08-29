#include "custom_lists.h"

/**
 * append_custom_node - appends a node at the end of a custom linked list
 * @custom_head: pointer to the first element in the custom list
 * @data: data to insert in the new element
 *
 * Returns: pointer to the new node, or NULL if it fails
 */
custom_node_t *append_custom_node(custom_node_t **custom_head, const int data)
{
    custom_node_t *new_node;
    custom_node_t *temp = *custom_head;

    new_node = malloc(sizeof(custom_node_t));
    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;

    if (*custom_head == NULL)
    {
        *custom_head = new_node;
        return new_node;
    }

    while (temp->next)
        temp = temp->next;

    temp->next = new_node;

    return new_node;
}
