/*
Problem Description
Imagine there are N people standing in a circle, numbered from 1 to N. Starting from a given position (e.g., person 1), you count off k people, and the k-th person is eliminated from the circle. The counting then resumes from the next person, and the process continues until only one person remains. The goal is to determine the position of the last survivor.

Example
Input:

Number of people, N = 5
Step rate, k = 2
Process:

People: 1 -> 2 -> 3 -> 4 -> 5 (in a circle)
Start counting from 1:
Eliminate person 2
Remaining: 1 -> 3 -> 4 -> 5
Eliminate person 4
Remaining: 1 -> 3 -> 5
Eliminate person 1
Remaining: 3 -> 5
Eliminate person 5
Remaining: 3
Output:

Survivor: 3

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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

struct Node* createCircularList(int N) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 1; i <= N; i++) {
        struct Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            temp->next = newNode;
            newNode->next = head; 
        }
        temp = newNode;
    }
    return head;
}

int josephusProblem(struct Node** head, int k) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        printf("Eliminated: %d\n", current->data);
        free(current);
        current = previous->next; 
    }
    *head = current;
    return current->data;
}

int main() {
    
    int N, k;

    printf("Enter the number of people (N): ");
    scanf("%d", &N);
    printf("Enter the step rate (k): ");
    scanf("%d", &k);
    struct Node* head = createCircularList(N);
    int survivor = josephusProblem(&head, k);
    printf("The survivor is: %d\n", survivor);
    free(head);

    return 0;
}
