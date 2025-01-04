#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure for the stack
typedef struct Stack {
    int* data;       // Array to store stack elements
    int top;         // Index of the top element
    int capacity;    // Maximum capacity of the stack
    int currentMin;  // Current minimum element in the stack
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    stack->currentMin = INT_MAX;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push operation
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }

    if (isEmpty(stack)) {
        stack->currentMin = value;
        stack->data[++stack->top] = value;
    } else {
        if (value < stack->currentMin) {
            // Store encoded value to keep track of the new minimum
            stack->data[++stack->top] = 2 * value - stack->currentMin;
            stack->currentMin = value;
        } else {
            stack->data[++stack->top] = value;
        }
    }

    printf("Pushed %d, Current Min: %d\n", value, stack->currentMin);
}

// Pop operation
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;
    }

    int poppedValue = stack->data[stack->top--];
    if (poppedValue < stack->currentMin) {
        // Retrieve the previous minimum
        int originalMin = stack->currentMin;
        stack->currentMin = 2 * stack->currentMin - poppedValue;
        printf("Popped %d (was encoded), New Min: %d\n", originalMin, stack->currentMin);
        return originalMin;
    }

    printf("Popped %d, Current Min: %d\n", poppedValue, stack->currentMin);
    return poppedValue;
}

// Function to get the minimum element
int getMin(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->currentMin;
}

// Main function to demonstrate the stack
int main() {
    int capacity, choice, value;

    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    Stack* stack = createStack(capacity);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Minimum\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;

            case 2:
                value = pop(stack);
                if (value != INT_MIN) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                value = getMin(stack);
                if (value != INT_MIN) {
                    printf("Current Minimum: %d\n", value);
                }
                break;

            case 4:
                printf("Exiting...\n");
                free(stack->data);
                free(stack);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
