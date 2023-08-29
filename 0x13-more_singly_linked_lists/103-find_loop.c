#include "custom_lists.h"

/**
 * custom_find_list_loop - finds the loop in a custom linked list
 * @custom_head: custom linked list to search for
 *
 * Returns: address of the node where the loop starts, or NULL
 */
custom_node_t *custom_find_list_loop(custom_node_t *custom_head)
{
    custom_node_t *slow = custom_head;
    custom_node_t *fast = custom_head;

    if (!custom_head)
        return NULL;

    while (slow && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            slow = custom_head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }

    return NULL;
}
