#include <stdio.h>
#include <math.h>
#include "search_algos.h"

skiplist_t *linear_skip(skiplist_t *list, int value) {
    if (list == NULL) {  // Handle NULL list
        return NULL;
    }

    // Find the first express level that doesn't exceed the value
    skiplist_t *current = list;
    while (current->express != NULL && current->express->n < value) {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        current = current->express;
    }

    // Search from the current level using linear search
    printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    while (current != NULL && current->n <= value) {
        if (current->n == value) {
            return current;  // Found the value
        }
        printf("Value checked at index [%lu] = [%d]\n", current->next->index, current->next->n);
        current = current->next;
    }

    return NULL;  // Value not found
}
