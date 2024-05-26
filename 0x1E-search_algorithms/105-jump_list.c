#include <stdio.h>
#include <math.h>
#include "search_algos.h"

listint_t *jump_list(listint_t *list, size_t size, int value) {
    if (list == NULL || size <= 0) {  // Handle NULL list or empty list
        return NULL;
    }

    // Calculate jump step (square root of list size)
    size_t jump = sqrt(size);

    // Current node and potential next jump node
    listint_t *current = list;
    listint_t *next = list;

    while (current != NULL && next != NULL && next->n < value) {
        // Print the value being checked for debugging
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

        // Move forward by the jump step
        for (size_t i = 0; i < jump && next != NULL; i++) {
            next = next->next;
        }
    }

    // Search within the narrowed range using linear search
    current = (next != NULL) ? next : current;  // Start from the last jump or current node
    while (current != NULL && current->n <= value) {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

        if (current->n == value) {
            return current;  // Found the value
        }

        current = current->next;
    }

    return NULL;  // Value not found
}
