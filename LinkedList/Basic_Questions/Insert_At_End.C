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


int main()
{
    int val;
    // add the value to linkedlist until you given -1 as input
    while(val!=-1){
        scanf("%d",&val);
            if (val!=-1){
                insert_at_end(val);
            }
    }
    display();
    return 0;
}
