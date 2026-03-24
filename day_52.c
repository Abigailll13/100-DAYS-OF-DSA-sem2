/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
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

// Build tree from level order input
Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* queue[1000];
    int front = 0, rear = 0;

    Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* parent = queue[front++];

        if (i < n && arr[i] != -1) {
            parent->left = newNode(arr[i]);
            queue[rear++] = parent->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            parent->right = newNode(arr[i]);
            queue[rear++] = parent->right;
        }
        i++;
    }
    return root;
}
Node* lca(Node* root, int p, int q) {
    if (root == NULL)                           return NULL;
    if (root->data == p || root->data == q)     return root;

    Node* leftLCA  = lca(root->left,  p, q);
    Node* rightLCA = lca(root->right, p, q);

    if (leftLCA  == NULL) return rightLCA;  // both in right subtree
    if (rightLCA == NULL) return leftLCA;   // both in left subtree
    return root;                            // one on each side = LCA
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    int p, q;
    scanf("%d %d", &p, &q);

    Node* result = lca(root, p, q);
    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("LCA not found\n");

    return 0;
}
