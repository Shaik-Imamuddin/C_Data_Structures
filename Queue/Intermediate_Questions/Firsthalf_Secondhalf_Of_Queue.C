#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* data;  // Dynamically allocated string
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = (char*)malloc(strlen(data) + 1);  // Allocate memory for the string
    strcpy(newNode->data, data);  // Copy the string into the node
    newNode->next = NULL;
    return newNode;
}

void enqueue(const char* data) {
    struct Node* newNode = createNode(data);
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

char* dequeue() {
    if (front == NULL) {
        return NULL;
    }
    struct Node* temp = front;
    char* data = temp->data;  // Get the string data
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);  // Free the node but keep the string
    return data;
}

int isEmpty() {
    return front == NULL;
}

void interleaveQueue() {
    if (front == NULL) {
        return;
    }

    struct Node* tempNode = front;
    int size = 0;

    // Calculate the size of the queue
    while (tempNode != NULL) {
        size++;
        tempNode = tempNode->next;
    }

    int mid = size / 2;

    // Store the first half of the queue
    char* firstHalf[mid];
    for (int i = 0; i < mid; i++) {
        firstHalf[i] = dequeue();
    }

    // Store the second half of the queue
    char* secondHalf[size - mid];
    for (int i = 0; i < size - mid; i++) {
        secondHalf[i] = dequeue();
    }

    // Interleave elements from both halves
    for (int i = 0; i < mid; i++) {
        enqueue(firstHalf[i]);  // Enqueue from the first half
        enqueue(secondHalf[i]); // Enqueue from the second half
    }

    // If the queue size is odd, enqueue the last element of the second half
    if (size % 2 != 0) {
        enqueue(secondHalf[mid]);
    }

    // Free the allocated memory for strings in arrays
    for (int i = 0; i < mid; i++) {
        free(firstHalf[i]);
    }
    for (int i = 0; i < size - mid; i++) {
        free(secondHalf[i]);
    }
}

void printQueue() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter the elements of the queue (space-separated):\n");
    for (int i = 0; i < n; i++) {
        char temp[32];
        scanf("%s", temp);  // Read the string
        enqueue(temp);  // Enqueue the string
    }

    printf("Original queue: ");
    printQueue();

    interleaveQueue();

    printf("Queue after interleaving: ");
    printQueue();

    return 0;
}

