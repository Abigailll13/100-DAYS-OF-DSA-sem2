/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(Node* root, int key) {
    if (root == NULL)       return false;  // not found
    if (key == root->data)  return true;   // found!
    if (key < root->data)   return search(root->left,  key);  // go left
    else                    return search(root->right, key);  // go right
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void showMenu() {
    printf("\n--- BST Search ---\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display (Inorder)\n");
    printf("4. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice, val;
    showMenu();

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Inserted: %d\n", val);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("%d FOUND in BST.\n", val);
                else
                    printf("%d NOT FOUND in BST.\n", val);
                break;

            case 3:
                printf("BST (inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
