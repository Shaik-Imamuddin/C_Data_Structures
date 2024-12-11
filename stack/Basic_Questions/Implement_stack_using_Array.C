#include <stdio.h>
#include <stdlib.h>

// Size of the array
#define MAX_SIZE 100 

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->data[++(stack->top)] = value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main() {
    Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Peek at the top element
    int topElement = peek(&stack);
    if (topElement != -1) {
        printf("Top element is %d.\n", topElement);
    }

    // Pop elements from the stack
    int poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Popped %d from the stack.\n", poppedValue);
    }

    poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Popped %d from the stack.\n", poppedValue);
    }

    if (isEmpty(&stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Popped %d from the stack.\n", poppedValue);
    }

    return 0;
}
