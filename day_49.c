/*Problem: BST Insert

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

// BST property:
// values smaller than root go LEFT
// values greater than root go RIGHT
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);   // empty spot found, place it here

    if (val < root->data)
        root->left  = insert(root->left,  val);  // go left
    else if (val > root->data)
        root->right = insert(root->right, val);  // go right
    // if val == root->data, do nothing (no duplicates in BST)

    return root;
}

// Print inorder (left → root → right) to verify BST — should print sorted
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert values one by one
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    /*
    Tree built:
            5
           / \
          3   7
         / \ / \
        1  4 6  8
    */

    printf("Inorder (expect 1 3 4 5 6 7 8): ");
    inorder(root);   // 1 3 4 5 6 7 8
    printf("\n");

    // Insert duplicate — should be ignored
    root = insert(root, 5);
    printf("After inserting duplicate 5: ");
    inorder(root);   // still 1 3 4 5 6 7 8
    printf("\n");

    // Insert into empty tree
    struct Node* root2 = NULL;
    root2 = insert(root2, 10);
    printf("Single node (expect 10): ");
    inorder(root2);  // 10
    printf("\n");

    return 0;
}


