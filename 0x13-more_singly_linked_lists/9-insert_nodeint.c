#include "custom_lists.h"

/**
 * custom_insert_node_at_index - inserts a new node in a custom linked list
 * at a specified position
 * @custom_head: pointer to the first node in the custom list
 * @index: index where the new node is added
 * @data: data to insert in the new node
 *
 * Returns: pointer to the new node, or NULL
 */
custom_node_t *custom_insert_node_at_index(custom_node_t **custom_head, unsigned int index, int data)
{
    unsigned int i;
    custom_node_t *new_node;
    custom_node_t *temp = *custom_head;

    new_node = malloc(sizeof(custom_node_t));
    if (!new_node || !custom_head)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;

    if (index == 0)
    {
        new_node->next = *custom_head;
        *custom_head = new_node;
        return new_node;
    }

    for (i = 0; temp && i < index; i++)
    {
        if (i == index - 1)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            return new_node;
        }
        else
            temp = temp->next;
    }

    return NULL;
}
