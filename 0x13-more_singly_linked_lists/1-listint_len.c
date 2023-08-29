#include "custom_lists.h"

/**
 * count_custom_elements - counts elements in a custom linked list
 * @custom_list: linked list of type custom_node_t to traverse
 *
 * Returns: number of nodes
 */
size_t count_custom_elements(const custom_node_t *custom_list)
{
    size_t count = 0;

    while (custom_list)
    {
        count++;
        custom_list = custom_list->next;
    }

    return count;
}
