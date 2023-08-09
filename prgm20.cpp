#include <stdio.h>
#include <stdlib.h>

int main() {
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    int arr1[size1];

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    int arr2[size2];

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Calculate the size of the concatenated array
    int sizeConcatenated = size1 + size2;

    int concatenatedArr[sizeConcatenated];

    // Copy elements from the first array
    for (int i = 0; i < size1; i++) {
        concatenatedArr[i] = arr1[i];
    }

    // Copy elements from the second array
    for (int i = 0; i < size2; i++) {
        concatenatedArr[size1 + i] = arr2[i];
    }

    printf("Concatenated array: ");
    for (int i = 0; i < sizeConcatenated; i++) {
        printf("%d ", concatenatedArr[i]);
    }
    printf("\n");

    return 0;
}

