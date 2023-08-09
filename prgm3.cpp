#include <stdio.h>

int main() {
    int a1, a2;
    printf("Enter the number of elements in a1: ");
    scanf("%d", &a1);
    printf("Enter the number of elements in a2: ");
    scanf("%d", &a2);
    int array1[a1], array2[a2], mergedArray[a1 + a2];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < a1; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < a2; i++) {
        scanf("%d", &array2[i]);
    }
    int index = 0;
    for (int i = 0; i < a1; i++) {
        mergedArray[index] = array1[i];
        index++;
    }
    for (int i = 0; i < a2; i++) {
        mergedArray[index] = array2[i];
        index++;
    }
    printf("Merged array:\n");
    for (int i = 0; i < a1 + a2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}

