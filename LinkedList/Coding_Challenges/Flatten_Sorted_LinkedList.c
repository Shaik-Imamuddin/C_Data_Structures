#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;  // Pointer to the next node in the main list
    struct Node* child; // Pointer to the head of the child list
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
    newNode->child = NULL;
    return newNode;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result;

    if (a->data < b->data) {
        result = a;
        result->child = mergeLists(a->child, b);
    } else {
        result = b;
        result->child = mergeLists(a, b->child);
    }

    return result;
}

// Function to flatten the list
struct Node* flattenList(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively flatten the next part of the list
    head->next = flattenList(head->next);

    // Merge current node's child list with the flattened next list
    head = mergeLists(head, head->next);

    return head;
}

// Function to print the flattened list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->child;
    }
    printf("\n");
}

// Function to create a user-defined list
struct Node* createUserList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int num, data;

    printf("Enter the number of nodes in the main list: ");
    scanf("%d", &num);
	int i;
    for (i = 0; i < num; i++) {
        printf("Enter data for node %d in the main list: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        int childCount;
        printf("Enter the number of child nodes for node %d: ", i + 1);
        scanf("%d", &childCount);

        struct Node* childHead = NULL;
        struct Node* childTail = NULL;
        int j;
        for (j = 0; j < childCount; j++) {
            printf("Enter data for child node %d of node %d: ", j + 1, i + 1);
            scanf("%d", &data);
            struct Node* childNode = createNode(data);

            if (childHead == NULL) {
                childHead = childTail = childNode;
            } else {
                childTail->child = childNode;
                childTail = childNode;
            }
        }
        newNode->child = childHead;
    }

    return head;
}

// Main function
int main() {
    printf("Create a sorted linked list with child pointers.\n");
    struct Node* head = createUserList();

    struct Node* flattenedList = flattenList(head);

    printf("\nFlattened sorted linked list:\n");
    printList(flattenedList);

    return 0;
}

