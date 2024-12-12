#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* link;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
    return head;
}

// Function to delete a node from a specific position
void deleteFromSpecificPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->link;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->link = temp->link;
    free(temp);
}

// Main function
int main() {
    struct Node* head = NULL;

    // Static input calls
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original list:\n");
    displayList(head);

    deleteFromSpecificPosition(&head, 2);
    printf("After deleting node at position 2:\n");
    displayList(head);

    deleteFromSpecificPosition(&head, 1);
    printf("After deleting node at position 1:\n");
    displayList(head);

    deleteFromSpecificPosition(&head, 3);
    printf("After deleting node at position 3:\n");
    displayList(head);

    return 0;
}

