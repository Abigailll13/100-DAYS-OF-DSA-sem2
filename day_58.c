/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees*/


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

// find position of value in inorder array
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

// preIndex tracks current root in preorder array
Node* buildTree(int* preorder, int* inorder, int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    // current root is always preorder[preIndex]
    int rootVal   = preorder[(*preIndex)++];
    Node* root    = newNode(rootVal);

    // find root in inorder → splits left and right subtrees
    int inIndex   = findIndex(inorder, inStart, inEnd, rootVal);

    // left subtree  → inorder[inStart ... inIndex-1]
    // right subtree → inorder[inIndex+1 ... inEnd]
    root->left  = buildTree(preorder, inorder, preIndex, inStart,    inIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[1000], inorder[1000];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, &preIndex, 0, n - 1);

    postorder(root);
    printf("\n");

    return 0;
}
