#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition of a doubly linked list node
struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new DLL node
struct DLLNode* createDLLNode(int data) {
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Global pointer to track the previous node in the DLL
struct DLLNode* prevNode = NULL;

// Function to convert a binary tree to a doubly linked list
struct DLLNode* binaryTreeToDLL(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Head of the doubly linked list
    static struct DLLNode* head = NULL;

    // Recursively convert the left subtree
    binaryTreeToDLL(root->left);

    // Process the current tree node
    struct DLLNode* current = createDLLNode(root->data);

    if (prevNode == NULL) {
        // This is the leftmost node, so it's the head of the DLL
        head = current;
    } else {
        // Link the previous node with the current node
        prevNode->next = current;
        current->prev = prevNode;
    }

    // Update the previous node to the current node
    prevNode = current;

    // Recursively convert the right subtree
    binaryTreeToDLL(root->right);

    return head;
}

// Function to print the doubly linked list
void printDLL(struct DLLNode* head) {
    printf("Doubly Linked List: ");
    struct DLLNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert nodes into a binary tree (level-order)
struct TreeNode* insertLevelOrder(struct TreeNode* root, int data) {
    struct TreeNode* newNode = createTreeNode(data);
    if (root == NULL) {
        return newNode;
    }

    // Use a queue for level-order insertion
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* temp = queue[front++];

        // Insert in the left child if it's empty
        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        // Insert in the right child if it's empty
        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }

    return root;
}

// Function to create a binary tree from user input
struct TreeNode* createBinaryTree() {
    struct TreeNode* root = NULL;
    int n, data;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insertLevelOrder(root, data);
    }

    return root;
}

// Main function
int main() {
    printf("Create a binary tree by entering nodes level-order.\n");

    // Create binary tree from user input
    struct TreeNode* root = createBinaryTree();

    // Convert the binary tree to a doubly linked list
    struct DLLNode* head = binaryTreeToDLL(root);

    // Print the doubly linked list
    printf("\nFlattened Doubly Linked List:\n");
    printDLL(head);

    return 0;
}

