/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* queue[1000];
    int front = 0, rear = 0;
    Node* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;
    while (i < n && front < rear) {
        Node* parent = queue[front++];
        if (i < n && arr[i] != -1) { parent->left  = newNode(arr[i]); queue[rear++] = parent->left;  } i++;
        if (i < n && arr[i] != -1) { parent->right = newNode(arr[i]); queue[rear++] = parent->right; } i++;
    }
    return root;
}

// ─────────────────────────────────────────
// ZIGZAG TRAVERSAL
// Use a temp array to store each level
// Even levels  → print left to right
// Odd  levels  → print right to left
// ─────────────────────────────────────────
void zigzagTraversal(Node* root) {
    if (root == NULL) return;

    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int level     = 0;   // 0 = left to right, 1 = right to left
    int firstNode = 1;   // to handle spaces between nodes

    while (front < rear) {
        int levelSize = rear - front;        // number of nodes at this level
        int temp[1000];

        // collect all nodes at this level
        for (int i = 0; i < levelSize; i++) {
            Node* curr = queue[front++];
            temp[i]    = curr->data;

            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        // print level left to right
        if (level % 2 == 0) {
            for (int i = 0; i < levelSize; i++) {
                if (!firstNode) printf(" ");
                printf("%d", temp[i]);
                firstNode = 0;
            }
        }
        // print level right to left
        else {
            for (int i = levelSize - 1; i >= 0; i--) {
                if (!firstNode) printf(" ");
                printf("%d", temp[i]);
                firstNode = 0;
            }
        }

        level++;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    zigzagTraversal(root);

    return 0;
}