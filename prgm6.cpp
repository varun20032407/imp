#include <stdio.h>

int searchNumber(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target number to search for: ");
    scanf("%d", &target);

    int index = searchNumber(arr, size, target);

    if (index != -1) {
        printf("The target number %d was found at index %d.\n", target, index);
    } else {
        printf("The target number %d was not found in the array.\n", target);
    }

    return 0;
}

