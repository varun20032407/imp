#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

struct TreeNode* findMin(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

struct TreeNode* findMax(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

int main() {
    struct TreeNode* root = NULL;
    int choice, value;
    
    do {
        printf("Binary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Find Minimum\n");
        printf("4. Find Maximum\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter a value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Element %d found in the tree.\n", value);
                } else {
                    printf("Element %d not found in the tree.\n", value);
                }
                break;
            case 3:
                if (root != NULL) {
                    struct TreeNode* minNode = findMin(root);
                    printf("Minimum element in the tree: %d\n", minNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 4:
                if (root != NULL) {
                    struct TreeNode* maxNode = findMax(root);
                    printf("Maximum element in the tree: %d\n", maxNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 5:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    // TODO: Free allocated memory for the tree nodes

    return 0;
}

