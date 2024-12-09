#include <stdio.h>
#include <stdlib.h>

// Structure definition for a Node
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

// Function to append a node to the circular linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        printf("Appended %d as the first node.\n", data);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
    printf("Appended %d to the list.\n", data);
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to delete the k-th node in the circular linked list
void deleteKthNode(struct Node** head, int k) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    // If the k-th node is the head node
    if (k == 1) {
        while (current->next != *head) {
            current = current->next;
        }
        if (current == *head) {
            free(*head);
            *head = NULL;
            printf("Deleted the only node in the list.\n");
            return;
        }
        current->next = (*head)->next;
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Deleted node at position %d (the head node).\n", k);
        return;
    }

    previous = *head;
    current = (*head)->next;
    int count = 2;

    // Traverse to the k-th node
    while (current != *head && count < k) {
        previous = current;
        current = current->next;
        count++;
    }

    if (count == k && current != *head) {
        previous->next = current->next;
        free(current);
        printf("Deleted node at position %d.\n", k);
    } else {
        printf("Position %d does not exist in the list.\n", k);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append to the list\n");
        printf("2. Delete a node at position k\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Operation aborted.\n");
                    break;
                }
                append(&head, value);
                break;

            case 2:
                printf("Enter the position (k) of the node to delete: ");
                if (scanf("%d", &position) != 1 || position < 1) {
                    printf("Invalid position. Operation aborted.\n");
                    break;
                }
                deleteKthNode(&head, position);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting...\n");
                if (head != NULL) {
                    struct Node* temp = head->next;
                    while (temp != head) {
                        struct Node* next = temp->next;
                        free(temp);
                        temp = next;
                    }
                    free(head);
                }
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

