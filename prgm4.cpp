#include <stdio.h>
#include <stdlib.h>

void findDuplicates(int arr[], int size) {
    printf("Duplicate values in the array: ");
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break; 
            }
        }
    }
    
    printf("\n");
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed for the array.\n");
        return 1;
    }
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    findDuplicates(arr, size);
    
    free(arr);
    
    return 0;
}

