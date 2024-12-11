#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a stack node
struct Node {
    char data;
    struct Node *link;
};

// Function to create a new node
struct Node* create_node(char data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Function to push a character onto the stack
struct Node* push(struct Node *top, char data) {
    struct Node *new_node = create_node(data);
    new_node->link = top;
    top = new_node;
    return top;
}

// Function to pop a character from the stack
char pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow! Cannot pop\n");
        return '\0';
    }
    struct Node *temp = *top;
    char popped_value = temp->data;
    *top = (*top)->link;
    free(temp);
    return popped_value;
}

// Function to reverse a string using a stack
void reverse_string(char *str) {
    struct Node *stack = NULL;  // Initialize an empty stack

    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        stack = push(stack, str[i]);
    }

    // Pop characters from the stack and overwrite the string
    int i = 0;
    while (stack != NULL) {
        str[i++] = pop(&stack);
    }
}

int main() {
    char str[10];

    printf("Enter a string: ");
    scanf("%[^\n]s", str);  // Read the input string (max 10 characters)

    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
	
