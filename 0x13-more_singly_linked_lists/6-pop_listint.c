#include "custom_lists.h"

/**
 * custom_pop_data - removes the first node from a custom linked list
 * @custom_head: pointer to the first element in the custom list
 *
 * Returns: the data inside the removed element, or 0 if the list is empty
 */
int custom_pop_data(custom_node_t **custom_head)
{
    custom_node_t *temp;
    int data = 0;

    if (!custom_head || !*custom_head)
        return 0;

    data = (*custom_head)->data;
    temp = (*custom_head)->next;
    free(*custom_head);
    *custom_head = temp;

    return data;
}
