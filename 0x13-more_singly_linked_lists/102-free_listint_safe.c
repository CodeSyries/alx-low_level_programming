#include "custom_lists.h"

/**
 * custom_free_list_safe - frees a custom linked list
 * @custom_head: pointer to the first node in the custom list
 *
 * Returns: number of elements in the freed list
 */
size_t custom_free_list_safe(custom_node_t **custom_head)
{
    size_t len = 0;
    int diff;
    custom_node_t *temp;

    if (!custom_head || !*custom_head)
        return 0;

    while (*custom_head)
    {
        diff = (int)(*custom_head) - (int)(*custom_head)->next;
        if (diff > 0)
        {
            temp = (*custom_head)->next;
            free(*custom_head);
            *custom_head = temp;
            len++;
        }
        else
        {
            free(*custom_head);
            *custom_head = NULL;
            len++;
            break;
        }
    }

    *custom_head = NULL;

    return len;
}
