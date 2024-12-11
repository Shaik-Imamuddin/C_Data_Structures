#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    struct Node* middle;
    int size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initializeStack(struct Stack* stack) {
    stack->top = NULL;
    stack->middle = NULL;
    stack->size = 0;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    if (stack->top == NULL) {
        stack->top = newNode;
        stack->middle = newNode;
    } else {
        newNode->next = stack->top;
        stack->top->prev = newNode;
        stack->top = newNode;
    }
    stack->size++;

    if (stack->size == 1) {
        stack->middle = stack->top;
    } else if (stack->size % 2 == 0) {
        stack->middle = stack->middle->prev;
    }
    printf("Pushed %d onto the stack.\n", data);
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    struct Node* temp = stack->top;
    int poppedData = temp->data;

    stack->top = stack->top->next;
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }
    stack->size--;

    if (stack->size == 0) {
        stack->middle = NULL;
    } else if (stack->size % 2 != 0) {
        stack->middle = stack->middle->next;
    }

    free(temp);
    printf("Popped %d from the stack.\n", poppedData);
    return poppedData;
}

int getMiddle(struct Stack* stack) {
    if (stack->middle == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->middle->data;
}

int deleteMiddle(struct Stack* stack) {
    if (stack->middle == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    struct Node* temp = stack->middle;
    int deletedData = temp->data;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (stack->size == 1) {
        stack->top = NULL;
        stack->middle = NULL;
    } else if (stack->size % 2 == 0) {
        stack->middle = stack->middle->prev;
    } else {
        stack->middle = stack->middle->next;
    }

    free(temp);
    stack->size--;
    printf("Deleted the middle element: %d\n", deletedData);
    return deletedData;
}

void displayStack(struct Stack* stack) {
    struct Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    displayStack(&stack);
    printf("Middle element: %d\n", getMiddle(&stack));

    pop(&stack);
    printf("Middle element after pop: %d\n", getMiddle(&stack));

    deleteMiddle(&stack);
    printf("Middle element after deleting middle: %d\n", getMiddle(&stack));

    displayStack(&stack);

    return 0;
}
