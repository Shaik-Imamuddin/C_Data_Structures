#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse nodes in groups of k
struct Node* reverseKGroup(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // Count the nodes in the list
    struct Node* temp = head;
    int totalNodes = 0;
    while (temp) {
        totalNodes++;
        temp = temp->next;
    }

    // If there are fewer than k nodes, return the list as is
    if (totalNodes < k) {
        return head;
    }

    // Reverse first k nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // After reversing, 'next' is the start of the next group
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    // 'prev' is the new head after reversing k nodes
    return prev;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, k;

    while (1) {
        printf("\n1. Append node\n2. Reverse in k groups\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                appendNode(&head, value);
                break;
            case 2:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                head = reverseKGroup(head, k);
                printf("List reversed in groups of %d.\n", k);
                break;
            case 3:
                printf("Current List: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

