/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/


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
// RIGHT VIEW
// At each level, print only the LAST node
// ─────────────────────────────────────────
void rightView(Node* root) {
    if (root == NULL) return;

    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int firstNode = 1;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            Node* curr = queue[front++];

            // last node of this level = rightmost = visible
            if (i == levelSize - 1) {
                if (!firstNode) printf(" ");
                printf("%d", curr->data);
                firstNode = 0;
            }

            if (curr->left)  queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
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
    rightView(root);

    return 0;
}
