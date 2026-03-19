/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int height(struct Node* node) {
    if (node == NULL) return -1;
    int leftHeight  = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    /*
         1          height = 2
        / \
       2   3
      / \
     4   5
    */
    struct Node* root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Test 1 : %d\n", height(root));           // 2
    printf("Test 2 : %d\n", height(newNode(42)));    // single node
    printf("Test 3 : %d\n", height(NULL));          // empty tree

    return 0;
}
