#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtTail(struct Node** head, int data) {
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
    newNode->prev = temp;
}

// Function to display the list
void displayList(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find pairs with a given sum
void findPairs(struct Node* head, int target) {
    struct Node* start = head;
    struct Node* end = head;

    // Move 'end' to the last node
    while (end->next != NULL) {
        end = end->next;
    }

    int found = 0;
    printf("Pairs with sum %d:\n", target);
    while (start != NULL && end != NULL && start != end && end->next != start) {
        int sum = start->data + end->data;

        if (sum == target) {
            printf("(%d, %d)\n", start->data, end->data);
            found = 1;
            start = start->next;
            end = end->prev;
        } else if (sum < target) {
            start = start->next;
        } else {
            end = end->prev;
        }
    }

    if (!found) {
        printf("No pairs found.\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, target;
    
    printf("\nMenu:\n");
    printf("1. Insert element\n");
    printf("2. Display list\n");
    printf("3. Find pairs with a target sum\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                if (head == NULL) {
                    printf("The list is empty. Please insert elements first.\n");
                } else {
                    printf("Enter the target sum: ");
                    scanf("%d", &target);
                    findPairs(head, target);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

