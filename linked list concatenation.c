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
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node*curr = *head;
    while (curr->next!= NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void displayList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node*curr = list1;
    while (curr->next!= NULL) {
        curr = curr->next;
    }
    curr->next = list2;
    return list1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);

    insertEnd(&list2, 4);
    insertEnd(&list2, 5);
    insertEnd(&list2, 6);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    list1 = concatenate(list1, list2);

    printf("Concatenated List: ");
    displayList(list1);

    return 0;
}
