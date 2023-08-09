#include <stdio.h>

void findElementLocations(int arr[], int size, int target) {
    printf("Locations of the target element %d: ", target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("%d ", i);  
        }
    }

    printf("\n");
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

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    findElementLocations(arr, size, target);

    return 0;
}

