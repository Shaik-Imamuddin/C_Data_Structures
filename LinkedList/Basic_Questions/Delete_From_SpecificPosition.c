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

void deleteFromSpecificPosition(int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;

    // If deleting the first node (position 1)
    if (position == 1) {
        head = temp->addr;
        printf("Successfully deleted the element: %d\n", temp->data);
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    int i;
    for (i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->addr;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->addr = temp->addr;
    printf("Successfully deleted the element: %d\n", temp->data);
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
    int choice, val, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete from Specific Position\n");
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
            printf("Enter Position to Delete: ");
            scanf("%d",&pos);
            deleteFromSpecificPosition(pos);
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
