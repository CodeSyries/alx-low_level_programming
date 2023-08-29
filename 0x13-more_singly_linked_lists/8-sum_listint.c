#include "custom_lists.h"

/**
 * calculate_custom_sum - computes the sum of data in a custom_node_t list
 * @custom_head: pointer to the first node in the custom list
 *
 * Returns: the calculated sum
 */
int calculate_custom_sum(custom_node_t *custom_head)
{
    int custom_sum = 0;
    custom_node_t *temp = custom_head;

    while (temp)
    {
        custom_sum += temp->data;
        temp = temp->next;
    }

    return custom_sum;
}
