#include <stdio.h>
#include <stdlib.h>

// Define a Node for the queue
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);

    if (q->rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        q->front = q->rear = newNode;
        printf("%d enqueued to the queue.\n", data);
        return;
    }

    // Add the new node at the end of the queue and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d enqueued to the queue.\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Return -1 to indicate an error
    }

    struct Node* temp = q->front;
    int dequeuedData = temp->data;

    // Move the front pointer to the next node
    q->front = q->front->next;

    // If the front becomes NULL, set the rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedData;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    struct Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue* q = createQueue();
    int choice, value;

    printf("Queue Operations Using Linked List:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Check if Queue is Empty\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2: // Dequeue
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3: // Display
                displayQueue(q);
                break;
            case 4: // Is Empty
                printf("Queue is %s\n", isEmpty(q) ? "Empty" : "Not Empty");
                break;
            case 5: // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

