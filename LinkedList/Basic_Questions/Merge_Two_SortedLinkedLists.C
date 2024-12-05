#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *link;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Function to display the linked list
void display_list(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Function to insert at the end of the list
struct node* insert_at_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_node;
    return head;
}

// Function to sort a linked list (Bubble Sort)
struct node* sort_linked_list(struct node *head) {
    if (head == NULL || head->link == NULL) {
        return head; // Already sorted if 0 or 1 node
    }

    struct node *current, *next_node;
    int temp_data;
    int swapped;

    do {
        swapped = 0;
        current = head;
        while (current->link != NULL) {
            next_node = current->link;
            if (current->data > next_node->data) {
                // Swap data
                temp_data = current->data;
                current->data = next_node->data;
                next_node->data = temp_data;
                swapped = 1;
            }
            current = current->link;
        }
    } while (swapped);

    return head;
}

// Function to merge two sorted linked lists
struct node* merge_sorted_lists(struct node *head1, struct node *head2) {
    struct node *dummy = create_node(0);
    struct node *current = dummy;

    // Merge both lists until one is exhausted
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->link = head1;
            head1 = head1->link;
        } else {
            current->link = head2;
            head2 = head2->link;
        }
        current = current->link;
    }

    // Attach the remaining nodes from the non-empty list
    if (head1 != NULL) {
        current->link = head1;
    } else if (head2 != NULL) {
        current->link = head2;
    }

    struct node *merged_head = dummy->link;
    free(dummy); // Free the dummy node
    return merged_head;
}

// Main function
int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *merged_head = NULL;
    int choice, data;

    printf("Create the first linked list:\n");
    while (1) {
        printf("Enter a value to insert into the first list (-1 to stop): ");
        scanf("%d", &data);
        if (data == -1) break;
        head1 = insert_at_end(head1, data);
    }

    printf("Create the second linked list\n");
    while (1) {
        printf("Enter a value to insert into the second list (-1 to stop): ");
        scanf("%d", &data);
        if (data == -1) break;
        head2 = insert_at_end(head2, data);
    }

    head1 = sort_linked_list(head1);
    printf("First sorted linked list:\n");
    display_list(head1);

    head2 = sort_linked_list(head2);
    printf("Second sorted linked list:\n");
    display_list(head2);

    merged_head = merge_sorted_lists(head1, head2);
    printf("Merged sorted linked list:\n");
    display_list(merged_head);

    return 0;
}

