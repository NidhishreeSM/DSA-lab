#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Declare pointers for 3 nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory for 3 nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign data and link nodes
    head->data = 10;       // first node data
    head->next = second;   // link first to second

    second->data = 20;     // second node data
    second->next = third;  // link second to third

    third->data = 30;      // third node data
    third->next = NULL;    // last node points to NULL

    // Traverse and print linked list
    struct Node *temp = head;
    printf("Linked List contains:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}

