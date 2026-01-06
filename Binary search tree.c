#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Search
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Search Tree Menu ---");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display (Inorder)");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted successfully.");
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value found in BST.");
                else
                    printf("Value not found in BST.");
                break;

            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                break;

            case 4:
                printf("Exiting program.");
                return 0;

            default:
                printf("Invalid choice!");
        }
    }
}
