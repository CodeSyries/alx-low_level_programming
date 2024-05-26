#include <stdio.h>
#include <math.h>

int jump_search(int *array, size_t size, int value) {
    if (array == NULL) {  // Handle NULL array case
        return -1;
    }

    int jump = sqrt(size);  // Calculate jump step
    int current = 0;  // Current position

    while (current < size && array[current] <= value) {
        printf("Value checked array[%d] = [%d]\n", current, array[current]);

        if (array[current] == value) {
            return current;  // Found the value
        }

        current += jump;  // Move to the next jump position
    }

    // If not found in the jumped locations, check the last block
    current -= jump;
    if (current >= 0 && current < size && array[current] == value) {
        printf("Value checked array[%d] = [%d]\n", current, array[current]);
        return current;  // Found in the last block
    }

    printf("Value found between indexes [%d] and [%zu]\n", current, size - 1);
    return -1;  // Not found
}

int main(void) {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
    printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
    printf("Found %d at index: %d\n", 999, jump_search(array, size, 999));
    return 0;
}
