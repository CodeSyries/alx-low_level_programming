#include "custom_lists.h"

/**
 * custom_free_list2 - frees a custom linked list
 * @custom_head: pointer to the custom_node_t list to be freed
 */
void custom_free_list2(custom_node_t **custom_head)
{
    custom_node_t *temp;

    if (custom_head == NULL)
        return;

    while (*custom_head)
    {
        temp = (*custom_head)->next;
        free(*custom_head);
        *custom_head = temp;
    }

    *custom_head = NULL;
}
