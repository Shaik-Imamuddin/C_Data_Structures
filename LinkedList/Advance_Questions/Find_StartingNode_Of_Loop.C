#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Detect the starting node of the loop
struct Node* findLoopStart(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect if a loop exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, a loop exists
        if (slow == fast) {
            // Step 2: Find the starting node of the loop
            slow = head;  // Reset slow to the head
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // The meeting point is the start of the loop
        }
    }

    return NULL;  // No loop
}

// Display the linked list (useful for debugging)
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;  // 50 -> 30

    struct Node* loopStart = findLoopStart(head);
    if (loopStart != NULL) {
        printf("Loop starts at node with data: %d\n", loopStart->data);
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}

