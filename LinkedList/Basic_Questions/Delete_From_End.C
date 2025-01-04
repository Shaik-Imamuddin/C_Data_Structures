#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *addr;
};

// Head pointer to point to the first node
struct Node *head = NULL;

// Function to create a new node and insert it at the end
void insert_at_end(int val) {
    // 1. Create memory for the new node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->data = val;
    newnode->addr = NULL;

    // 3. Handle the case for the first node
    if (head == NULL) {
        head = newnode;
        return;
    }

    // 4. Traverse the list to find the last node
    struct Node *temp = head;
    while (temp->addr != NULL) {
        temp = temp->addr;
    }
    temp->addr = newnode; // Link the new node to the last node
}

// Function to delete a node from the end
void delete_from_end() {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    if (head->addr == NULL) { // Only one node in the list
     	printf("Successfully deleted the element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Traverse to the last node
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->addr != NULL) {
        prev = temp;
        temp = temp->addr;
    }
    printf("Successfully deleted the element: %d\n", temp->data);
    prev->addr = NULL; // Disconnect the last node
    free(temp);
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete from end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert_at_end(val);
            break;
        case 2:
            delete_from_end();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
