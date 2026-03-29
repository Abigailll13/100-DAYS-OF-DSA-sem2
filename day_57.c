/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/

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
void mirror(Node* root) {
    if (root == NULL) return;
    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* root = buildTree(arr, n);
    mirror(root);
    inorder(root);
    return 0;
}