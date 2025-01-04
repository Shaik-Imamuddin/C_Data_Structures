#include<stdio.h>
#include<stdlib.h>
// Structure of a node
struct Node{
    int data;
    struct Node *addr;
};

// head pointer to point the first node
struct Node *head = NULL;

//Function to create node memory and insert data into linkedlist
void insert_at_end(int val)
{
    //1.create a memory for the node
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
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
        struct Node *temp = head;
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
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->addr;
    }
    printf("\n");
}


// Search for a value
void searchElement(int key) {
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->addr;
        position++;
    }
    printf("Element %d not found.\n", key);
}


// Main function
int main() {
struct node *head = NULL;
int choice, data, position;
while (1) {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Display Linked List\n");
    printf("3. Search An Element\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &data);
            searchElement(data);
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
