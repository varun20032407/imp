#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int fifthIteratedElement = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            fifthIteratedElement = arr[j];
        }
    }

    printf("The 5th iterated element is: %d\n", fifthIteratedElement);

    return 0;
}

