/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/

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

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left  = insert(root->left,  val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// LCA in BST:
// if both p and q are smaller  → LCA is in left subtree
// if both p and q are greater  → LCA is in right subtree
// otherwise                    → current node is the LCA
Node* lca(Node* root, int p, int q) {
    if (root == NULL) return NULL;

    if (p < root->data && q < root->data)
        return lca(root->left,  p, q);   // both smaller, go left

    if (p > root->data && q > root->data)
        return lca(root->right, p, q);   // both greater, go right

    return root;                          // split point = LCA
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    Node* result = lca(root, p, q);
    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("LCA not found\n");

    return 0;
}
