#include "custom_lists.h"
#include <stdio.h>

size_t custom_looped_list_len(const custom_node_t *custom_head);
size_t custom_print_list_safe(const custom_node_t *custom_head);

/**
 * custom_looped_list_len - Counts the number of unique nodes
 * in a looped custom_node_t linked list.
 * @custom_head: A pointer to the head of the custom_node_t list to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t custom_looped_list_len(const custom_node_t *custom_head)
{
    const custom_node_t *tortoise, *hare;
    size_t nodes = 1;

    if (custom_head == NULL || custom_head->next == NULL)
        return 0;

    tortoise = custom_head->next;
    hare = (custom_head->next)->next;

    while (hare)
    {
        if (tortoise == hare)
        {
            tortoise = custom_head;
            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
                hare = hare->next;
            }

            tortoise = tortoise->next;
            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
            }

            return nodes;
        }

        tortoise = tortoise->next;
        hare = (hare->next)->next;
    }

    return 0;
}

/**
 * custom_print_list_safe - Prints a custom_node_t list safely.
 * @custom_head: A pointer to the head of the custom_node_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t custom_print_list_safe(const custom_node_t *custom_head)
{
    size_t nodes, index = 0;

    nodes = custom_looped_list_len(custom_head);

    if (nodes == 0)
    {
        for (; custom_head != NULL; nodes++)
        {
            printf("[%p] %d\n", (void *)custom_head, custom_head->data);
            custom_head = custom_head->next;
        }
    }
    else
    {
        for (index = 0; index < nodes; index++)
        {
            printf("[%p] %d\n", (void *)custom_head, custom_head->data);
            custom_head = custom_head->next;
        }

        printf("-> [%p] %d\n", (void *)custom_head, custom_head->data);
    }

    return nodes;
}
