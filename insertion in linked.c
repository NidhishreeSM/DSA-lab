#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtMiddle(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    int length = 0;
    struct Node* temp = *head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    int afterPos = (length % 2 == 0) ? (length / 2) : ((length + 1) / 2);

    temp = *head;
    int i;
    for (i = 1; i < afterPos && temp->next != NULL; i++) {
    temp = temp->next;
}
    newNode->next = temp->next;
    temp->next = newNode;
}

int main(void) {
    struct Node* head = NULL;

    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Original list: ");
    printList(head);

    insertAtMiddle(&head, 99);

    printf("After middle insertion: ");
    printList(head);

    return 0;
}
