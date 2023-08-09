#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where target is found
        }
    }
    return -1;  // Return -1 if target is not found
}

// Binary Search Function (Assumes the array is sorted)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Return the index where target is found
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Return -1 if target is not found
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Perform Linear Search
    int linearIndex = linearSearch(arr, size, target);
    if (linearIndex != -1) {
        printf("Linear Search: Element %d found at index %d.\n", target, linearIndex);
    } else {
        printf("Linear Search: Element %d not found in the array.\n", target);
    }

    // Perform Binary Search
    int binaryIndex = binarySearch(arr, size, target);
    if (binaryIndex != -1) {
        printf("Binary Search: Element %d found at index %d.\n", target, binaryIndex);
    } else {
        printf("Binary Search: Element %d not found in the array.\n", target);
    }

    return 0;
}

