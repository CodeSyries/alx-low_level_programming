#include "custom_lists.h"

/**
 * custom_delete_node_at_index - deletes a node in a custom linked list at a specific index
 * @custom_head: pointer to the first node in the custom list
 * @index: index of the node to delete
 *
 * Returns: 1 (Success), or -1 (Failure)
 */
int custom_delete_node_at_index(custom_node_t **custom_head, unsigned int index)
{
    custom_node_t *temp = *custom_head;
    custom_node_t *current = NULL;
    unsigned int i = 0;

    if (*custom_head == NULL)
        return -1;

    if (index == 0)
    {
        *custom_head = (*custom_head)->next;
        free(temp);
        return 1;
    }

    while (i < index - 1)
    {
        if (!temp || !(temp->next))
            return -1;
        temp = temp->next;
        i++;
    }

    current = temp->next;
    temp->next = current->next;
    free(current);

    return 1;
}
