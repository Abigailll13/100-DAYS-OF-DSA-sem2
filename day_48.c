/*Problem: Count Leaf Nodes

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

// A leaf node is one with NO left and NO right child
int countLeaves(struct Node* root) {
    if (root == NULL)                           return 0;  // empty tree
    if (root->left == NULL && root->right == NULL) return 1;  // it's a leaf!

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    /*
         1
        / \
       2   3
      / \
     4   5
    
    Leaves: 4, 5, 3  → count = 3
    */
    struct Node* root     = newNode(1);
    root->left            = newNode(2);
    root->right           = newNode(3);
    root->left->left      = newNode(4);
    root->left->right     = newNode(5);

    printf("Test 1 : %d\n", countLeaves(root));       // 3

    // Single node — root itself is a leaf
    printf("Test 2 : %d\n", countLeaves(newNode(1))); // 1

    // Empty tree
    printf("Test 3 : %d\n", countLeaves(NULL));       // 0

    return 0;
}
