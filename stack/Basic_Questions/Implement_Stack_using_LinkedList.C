//stack using linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *link;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
    // Check if memory allocation is successful
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Function to push an element onto the stack (insert at the beginning)
struct node* push(struct node *top, int data) {
    struct node *new_node = create_node(data);
    new_node->link = top;  // Set the new node's link to the current top
    top = new_node;        // Update the top to the new node
    printf("%d pushed to stack\n", data);
    return top;            // Return the updated top of the stack
}

// Function to pop an element from the stack (remove from the beginning)
int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Return -1 to indicate an error
    }
    struct node *temp = *top;
    int popped_value = temp->data; // Get the data of the top node
    *top = (*top)->link; // Update the top to the next node
    free(temp); // Free the memory of the popped node
    return popped_value;
}

// Function to peek the top element of the stack
int peek(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    }
    return top->data; // Return the data of the top node
}

// Function to display the stack
void display_stack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL; // Initialize an empty stack

    // Push elements onto the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);

    // Display the stack
    display_stack(top);

    // Peek the top element
    printf("Top element: %d\n", peek(top));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));
    printf("Popped element: %d\n", pop(&top));

    // Display the stack after popping
    display_stack(top);

    return 0;
}
