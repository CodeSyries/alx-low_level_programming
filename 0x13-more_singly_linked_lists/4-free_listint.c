#include "custom_lists.h"

/**
 * custom_free_list - frees a custom linked list
 * @custom_head: custom_node_t list to be freed
 */
void custom_free_list(custom_node_t *custom_head)
{
    custom_node_t *temp;

    while (custom_head)
    {
        temp = custom_head->next;
        free(custom_head);
        custom_head = temp;
    }
}
