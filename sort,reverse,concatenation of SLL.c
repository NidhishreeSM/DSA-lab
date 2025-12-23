#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}


void concatenate(struct Node** head1, struct Node* head2) {
    struct Node* temp = *head1;

    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, data, n, i;

    do {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
            }
            break;

        case 2:
            printf("Enter number of elements: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
            }
            break;

        case 3:
            printf("List 1: ");
            display(list1);
            break;

        case 4:
            printf("List 2: ");
            display(list2);
            break;

        case 5:
            sortList(list1);
            printf("List 1 sorted successfully.\n");
            break;

        case 6:
            reverseList(&list1);
            printf("List 1 reversed successfully.\n");
            break;

        case 7:
            concatenate(&list1, list2);
            printf("Lists concatenated successfully.\n");
            break;

        case 8:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}

