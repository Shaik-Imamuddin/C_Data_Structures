#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *addr;
};

// Head pointer to point to the first node
struct Node *head = NULL;

// Function to create a new node and insert it at a specific position
void insert_at_position(int val, int pos) {
    // 1. Create memory for the new node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->data = val;
    newnode->addr = NULL;

    // 3. Handle the case for insertion at the beginning (position 1)
    if (pos == 1) {
        newnode->addr = head;
        head = newnode;
        return;
    }

    // 4. Traverse the list to find the position
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->addr;
    }

    // 5. If the position is invalid, handle the error
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    // 6. Insert the new node at the correct position
    newnode->addr = temp->addr;
    temp->addr = newnode;
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

int main()
{
    int val,pos;
    // add the value to linkedlist until you given -1 as input
    while(val!=-1){
        scanf("%d",&val);
            if (val==-1){
                break;
            }
            scanf("%d",&pos);
            insert_at_position(val,pos);
    }
    display();
    return 0;
}
