#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Definition of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new linked list node
struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new binary tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the middle node of the linked list
struct ListNode* findMiddle(struct ListNode* head, struct ListNode** prev) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        *prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to convert a sorted linked list into a balanced BST
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* prev = NULL;
    struct ListNode* mid = findMiddle(head, &prev);

    // Create the root node with the middle element
    struct TreeNode* root = createTreeNode(mid->data);

    // If the middle element is the head, no left subtree
    if (mid == head) {
        root->left = NULL;
    } else {
        prev->next = NULL; // Break the list into two halves
        root->left = sortedListToBST(head); // Recursively construct the left subtree
    }

    root->right = sortedListToBST(mid->next); // Recursively construct the right subtree

    return root;
}

// Function to print the inorder traversal of the tree
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to print the preorder traversal of the tree
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to print the postorder traversal of the tree
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to get user input for a sorted linked list
struct ListNode* createUserList() {
    int n, data;
    struct ListNode *head = NULL, *tail = NULL;

    printf("Enter the number of elements in the sorted linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        struct ListNode* newNode = createListNode(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Main function
int main() {
    // Create a sorted linked list
    printf("Create a sorted linked list:\n");
    struct ListNode* head = createUserList();

    // Convert the sorted linked list into a balanced BST
    struct TreeNode* root = sortedListToBST(head);

    // Print the traversals of the BST
    printf("\nInorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal of the constructed BST: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the constructed BST: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

