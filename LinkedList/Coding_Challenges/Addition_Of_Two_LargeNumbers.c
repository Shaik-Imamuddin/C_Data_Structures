#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to insert a node at the tail
void insertAtTail(struct Node** head, int data) {
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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two large numbers represented as linked lists
struct Node* addLargeNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry > 0) {
        int sum = carry;

        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        // Insert the sum digit at the tail
        insertAtTail(&result, sum);
    }

    return result;
}

// Function to print a linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to create a linked list from a string representation of a number
struct Node* createListFromString(char* number) {
    struct Node* head = NULL;
    int length = strlen(number);
	int i;
    for (i = length - 1; i >= 0; i--) {
        insertAtTail(&head, number[i] - '0');
    }

    return head;
}

// Main function
int main() {
    char num1[1000], num2[1000];

    printf("Enter the first large number: ");
    scanf("%s", num1);

    printf("Enter the second large number: ");
    scanf("%s", num2);

    // Create linked lists from the input strings
    struct Node* list1 = createListFromString(num1);
    struct Node* list2 = createListFromString(num2);

    // Add the two numbers
    struct Node* result = addLargeNumbers(list1, list2);

    // Reverse the result to display in correct order
    result = reverseList(result);

    printf("The sum is: ");
    display(result);

    return 0;
}

