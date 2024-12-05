#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two numbers represented as linked lists
struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node** current = &result;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        *current = createNode(digit);
        current = &((*current)->next);
    }

    return result;
}

// Main function
int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    // Create the first number
    appendNode(&num1, 3);
    appendNode(&num1, 4);
    appendNode(&num1, 2);

    // Create the second number
    appendNode(&num2, 4);
    appendNode(&num2, 6);
    appendNode(&num2, 5);

    printf("First number: ");
    printList(num1);
    printf("Second number: ");
    printList(num2);

    // Reverse the lists
    num1 = reverseList(num1);
    num2 = reverseList(num2);

    // Add the two numbers
    struct Node* result = addTwoLists(num1, num2);

    // Reverse the result to match the correct order
    result = reverseList(result);

    printf("Sum: ");
    printList(result);

    return 0;
}

