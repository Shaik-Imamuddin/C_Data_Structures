#include<stdio.h>
#include<stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *addr;
};

// Head pointer to point the first node
struct Node *head = NULL;

// Function to create node memory and insert data at the beginning of the linked list
void insert_at_beginning(int val) {
    // 1. Create memory for the new node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->data = val;
    newnode->addr = NULL;
    // 3. Connection: point the new node to the current head
    newnode->addr = head;
    // 4. Update head to the new node
    head = newnode;
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
    int val;
    // add the value to linkedlist until you given -1 as input
    while(val!=-1){
        scanf("%d",&val);
            if (val!=-1){
                insert_at_beginning(val);
            }
    }
    display();
    return 0;
}
