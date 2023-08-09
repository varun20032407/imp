#include <stdio.h>
#include <stdbool.h>

void findMissingElements(int arr[], int size) {
    // Find the maximum and minimum values in the array
    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    // Create a boolean array to mark the presence of elements
    bool present[max - min + 1];
    for (int i = 0; i < max - min + 1; i++) {
        present[i] = false;
    }
    
    // Mark the presence of elements from the input array
    for (int i = 0; i < size; i++) {
        present[arr[i] - min] = true;
    }
    
    // Print missing elements
    printf("Missing elements: ");
    for (int i = 0; i < max - min + 1; i++) {
        if (!present[i]) {
            printf("%d ", i + min);
        }
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    findMissingElements(arr, size);

    return 0;
}

