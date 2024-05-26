#include <stdio.h>

int binary_search(int *array, size_t size, int value) {
    if (array == NULL) {  // Handle NULL array case
        return -1;
    }

    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;  // Avoid overflow by calculating mid this way

        printf("Searching subarray: [");
        for (int i = left; i <= right; i++) {
            printf("%d, ", array[i]);
        }
        printf("]\n");

        if (array[mid] == value) {
            return mid;  // Found the value
        } else if (array[mid] < value) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }

    return -1;  // Not found
}

int main(void) {
    int array[] = {1, 3, 5, 7, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n", 5, binary_search(array, size, 5));
    printf("Found %d at index: %d\n", 10, binary_search(array, size, 10));
    return 0;
}
