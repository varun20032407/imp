#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node *mergeLists(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    struct Node *mergedList = NULL;
    struct Node *current = NULL;
    
    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }
    
    current = mergedList;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    return mergedList;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    
    int n1, n2, value;
    
    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n1);
    
    printf("Enter the elements of the first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (list1 == NULL) {
            list1 = newNode;
        } else {
            struct Node *temp = list1;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n2);
    
    printf("Enter the elements of the second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (list2 == NULL) {
            list2 = newNode;
        } else {
            struct Node *temp = list2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    printf("First list: ");
    printList(list1);
    
    printf("Second list: ");
    printList(list2);
    
    struct Node *mergedList = mergeLists(list1, list2);
    
    printf("Merged list: ");
    printList(mergedList);
    
    // Free allocated memory
    while (mergedList != NULL) {
        struct Node *temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
    
    return 0;
}

