#include <stdio.h>
#include <math.h>

int exponential_search(int *array, size_t size, int value) {
    if (array == NULL || size <= 0) {  // Handle NULL array or empty array
        return -1;
    }

    int i = 1;  // Initialize exponent

    while (i < size && array[i] <= value) {
        i *= 2;  // Double the exponent for the next search range
    }

    // Restrict i within array bounds
    i = fmin(i, size - 1);  // Ensure i doesn't exceed the last element's index

    printf("Value found between indexes [%d] and [%zu]\n", i / 2, size - 1);

    // Print the subarray to be searched using binary search
    printf("Searching in array: ");
    for (size_t j = i / 2; j < size; j++) {
        printf("%d, ", array[j]);
    }
    printf("\n");

    return binary_search(array + i / 2, size - (i / 2), value);  // Binary search within the subarray
}

// Assuming binary_search function is defined elsewhere (not shown here)
int binary_search(int *array, size_t size, int value) {
    // Implement binary search logic to find the index within the subarray
    // ...
}

int main(void) {
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 62, exponential_search(array, size, 62));
    printf("Found %d at index: %d\n\n", 3, exponential_search(array, size, 3));
    printf("Found %d at index: %d\n", 999, exponential_search(array, size, 999));
    return 0;
}

