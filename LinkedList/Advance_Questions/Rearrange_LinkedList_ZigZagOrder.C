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

// Append a node to the linked list
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

// Rearrange the linked list in zigzag order
void rearrangeZigzag(struct Node* head) {
    int flag = 1;  // 1 means "<" condition, 0 means ">" condition
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (flag && current->data > current->next->data) {
            // Swap for "<" condition
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        } else if (!flag && current->data < current->next->data) {
            // Swap for ">" condition
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        }
        flag = !flag;  // Toggle flag for next pair
        current = current->next;
    }
}

// Display the linked list
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
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Append node\n2. Rearrange in zigzag order\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                appendNode(&head, value);
                break;
            case 2:
                rearrangeZigzag(head);
                printf("List rearranged in zigzag order.\n");
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

