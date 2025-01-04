#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *addr;
};

struct node *head = NULL;

//Function to create node memory and insert data into linkedlist
void insert_at_end(int val)
{
    //1.create a memory for the node
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    //2.initialize the node memory
    newnode->data = val;
    newnode->addr = NULL;
    //3. connection
    // check for first node connection (head to first node)
    if(head==NULL)
    {
        head = newnode;
    }
    // rest of the nodes with previous nodes
    else
    {
        struct node *temp = head;
        // to find last node
        while(temp->addr!=NULL)
        {
            temp = temp->addr;
        }
        temp->addr = newnode;
    }
}

// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}
// Function to reverse the linked list
struct node* reverseLinkedList(struct node* head) {
    struct node* prev = NULL;    // Pointer to store the previous node
    struct node* current = head; // Pointer to traverse the list
    struct node* next = NULL;    // Pointer to store the next node

    while (current != NULL) {
        next = current->addr;    // Save the next node
        current->addr = prev;    // Reverse the current node's link
        prev = current;          // Move the prev pointer forward
        current = next;          // Move the current pointer forward
    }

    return prev; // New head of the reversed list
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Reverse the Linked List\n");
        printf("3. Display Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert : ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 2:
                head = reverseLinkedList(head);
                printf("Reversed Linked List:\n");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
