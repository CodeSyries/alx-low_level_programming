#include "custom_lists.h"

/**
 * custom_reverse_list - reverses a custom linked list
 * @custom_head: pointer to the first node in the custom list
 *
 * Returns: pointer to the first node in the reversed list
 */
custom_node_t *custom_reverse_list(custom_node_t **custom_head)
{
    custom_node_t *prev = NULL;
    custom_node_t *next = NULL;

    while (*custom_head)
    {
        next = (*custom_head)->next;
        (*custom_head)->next = prev;
        prev = *custom_head;
        *custom_head = next;
    }

    *custom_head = prev;

    return *custom_head;
}
