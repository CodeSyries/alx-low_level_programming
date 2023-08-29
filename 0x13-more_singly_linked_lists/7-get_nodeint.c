#include "custom_lists.h"

/**
 * get_custom_node_at_index - retrieves a node at a specific index in a custom linked list
 * @custom_head: pointer to the first node in the custom list
 * @index: index of the node to retrieve
 *
 * Returns: pointer to the requested node, or NULL if not found
 */
custom_node_t *get_custom_node_at_index(custom_node_t *custom_head, unsigned int index)
{
    unsigned int i = 0;
    custom_node_t *temp = custom_head;

    while (temp && i < index)
    {
        temp = temp->next;
        i++;
    }

    return temp ? temp : NULL;
}
