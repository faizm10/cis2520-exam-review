#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly-linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to print the linked list
void printList(struct Node *n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

int main() {
    // Linked list with 3 nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign data and link nodes
    head->data = 1;      // Assign data to the first node
    head->next = second; // Link first node with second

    second->data = 2;    // Assign data to the second node
    second->next = third; // Link second node with third

    third->data = 3;    // Assign data to the third node
    third->next = NULL;  // Terminate the list

    // Print the linked list
    printList(head);

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
