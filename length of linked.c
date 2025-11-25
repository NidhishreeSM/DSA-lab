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

int getLength(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Length of linked list: %d\n", getLength(head));

    int key = 20;
    if (searchElement(head, key))
        printf("Element %d found in the list.\n", key);
    else
        printf("Element %d not found in the list.\n", key);

    return 0;
}
