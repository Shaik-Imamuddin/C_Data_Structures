#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the nth node from the end
struct Node* findNthFromEnd(struct Node* head, int n) {
    struct Node* first = head;
    struct Node* second = head;

    // Move the 'first' pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == NULL) {
            return NULL; // If the list has fewer than n nodes
        }
        first = first->next;
    }

    // Move both pointers until the 'first' pointer reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second; // The 'second' pointer is at the nth node from the end
}

// Main function
int main() {
    struct Node* head = NULL;
    int value, n;

    printf("Enter elements for the linked list (enter -1 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);
        if (value == -1) break; // Stop input when -1 is entered
        head = insertAtEnd(head, value); // Append the value to the list
    }

    printf("Linked List: ");
    displayList(head);

    printf("Enter n value to find the nth node from the end: ");
    scanf("%d", &n);

    struct Node* nthNode = findNthFromEnd(head, n);
    if (nthNode != NULL) {
        printf("The %dth node from the end is: %d\n", n, nthNode->data);
    } else {
        printf("The list has fewer than %d nodes.\n", n);
    }

    return 0;
}
