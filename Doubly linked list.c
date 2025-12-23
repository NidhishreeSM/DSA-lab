#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createList(struct Node** head, int n) {
    int data;
    int i;
    struct Node *temp, *newNode;

    if (*head == NULL) {
        temp = NULL;
    } else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);

        newNode = createNode(data);

        if (*head == NULL) {
            *head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}


void insertLeft(struct Node** head, int key, int data) {
    struct Node* temp = *head;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp->data == key) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list\n", key);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }


    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list\n", key);
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, n, key, data;

    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert a node to the left of a value\n");
        printf("3. Delete a node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(&head, n);
            break;

        case 2:
            printf("Enter value to insert before: ");
            scanf("%d", &key);
            printf("Enter new data: ");
            scanf("%d", &data);
            insertLeft(&head, key, data);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

