#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Structure for a stack node
struct StackNode {
    int x, y;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createNode(int x, int y) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

// Push an element to the stack
void push(struct StackNode** top, int x, int y) {
    struct StackNode* newNode = createNode(x, y);
    newNode->next = *top;
    *top = newNode;
}

// Pop an element from the stack
void pop(struct StackNode** top) {
    if (*top == NULL) return;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
}

// Check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Get the top element of the stack
struct StackNode* top(struct StackNode* stack) {
    return stack;
}

// Function to check if a cell is valid and part of the island
int isValid(int grid[ROWS][COLS], int visited[ROWS][COLS], int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] == 1 && !visited[x][y]);
}

// Perform DFS using a stack
int dfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int startX, int startY) {
    int area = 0;
    int rowOffsets[] = {-1, 1, 0, 0};
    int colOffsets[] = {0, 0, -1, 1};

    struct StackNode* stack = NULL;
    push(&stack, startX, startY);

    while (!isEmpty(stack)) {
        struct StackNode* current = top(stack);
        int x = current->x;
        int y = current->y;
        pop(&stack);

        if (!visited[x][y]) {
            visited[x][y] = 1;
            area++;

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int newX = x + rowOffsets[i];
                int newY = y + colOffsets[i];
                if (isValid(grid, visited, newX, newY)) {
                    push(&stack, newX, newY);
                }
            }
        }
    }

    return area;
}

// Find the maximum area of an island
int maxAreaOfIsland(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0};
    int maxArea = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int area = dfs(grid, visited, i, j);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }

    return maxArea;
}

int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0}
    };

    printf("Maximum area of an island: %d\n", maxAreaOfIsland(grid));

    return 0;
}

