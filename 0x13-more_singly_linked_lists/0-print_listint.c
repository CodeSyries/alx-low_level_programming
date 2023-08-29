#include "custom_lists.h"

/**
 * display_custom_list - displays elements of a custom linked list
 * @list: custom linked list of type custom_node_t
 *
 * Returns: the count of nodes in the list
 */
size_t display_custom_list(const custom_node_t *list)
{
    size_t count = 0;

    while (list)
    {
        printf("%d\n", list->data);
        count++;
        list = list->next;
    }

    return count;
}
