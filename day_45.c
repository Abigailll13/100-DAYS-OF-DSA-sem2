/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* queue[1000];
    int front = 0, rear = 0;

    Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* parent = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            parent->left = newNode(arr[i]);
            queue[rear++] = parent->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            parent->right = newNode(arr[i]);
            queue[rear++] = parent->right;
        }
        i++;
    }
    return root;
}

// Find height recursively
int height(Node* root) {
    if (root == NULL) return 0;

    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);

    // Height = 1 (current node) + max of left and right
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    printf("%d\n", height(root));

    return 0;
}
