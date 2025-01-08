#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* queue1Front = NULL;
struct Node* queue1Rear = NULL;
struct Node* queue2Front = NULL;
struct Node* queue2Rear = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

int isEmpty(struct Node* front) {
    return front == NULL;
}

void push(int data) {
    enqueue(&queue1Front, &queue1Rear, data);
}

int pop() {
    if (isEmpty(queue1Front)) {
        printf("Stack is empty!\n");
        return -1;
    }

    while (queue1Front->next != NULL) {
        int data = dequeue(&queue1Front, &queue1Rear);
        enqueue(&queue2Front, &queue2Rear, data);
    }

    int poppedData = dequeue(&queue1Front, &queue1Rear);
    // Swap the roles of queue1 and queue2
    struct Node* tempFront = queue1Front;
    struct Node* tempRear = queue1Rear;
    queue1Front = queue2Front;
    queue1Rear = queue2Rear;
    queue2Front = tempFront;
    queue2Rear = tempRear;

    return poppedData;
}

void displayStack() {
    if (isEmpty(queue1Front)) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = queue1Front;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("\nStack Operations using Two Queues:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
