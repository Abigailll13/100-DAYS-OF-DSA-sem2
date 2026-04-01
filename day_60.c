/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/

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
// MIN HEAP PROPERTY:
// Every parent must be SMALLER than
// both its children at every node
// ─────────────────────────────────────────
int isMinHeap(Node* root) {
    if (root == NULL) return 1;

    // check left child
    if (root->left != NULL && root->left->data < root->data)
        return 0;

    // check right child
    if (root->right != NULL && root->right->data < root->data)
        return 0;

    // recurse both sides
    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    printf("%s\n", isMinHeap(root) ? "YES" : "NO");

    return 0;
}
