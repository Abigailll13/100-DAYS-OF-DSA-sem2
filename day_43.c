#include <stdio.h>
#include <stdlib.h>
// Tree node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order input
Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);

    // Queue to track parent nodes
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* parent = queue[front++];

        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                parent->left = newNode(arr[i]);
                queue[rear++] = parent->left;
            }
            i++;
        }

        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                parent->right = newNode(arr[i]);
                queue[rear++] = parent->right;
            }
            i++;
        }
    }

    return root;
}

// Inorder traversal: Left → Root → Right
void inorder(Node* root, int* first) {
    if (!root) return;
    inorder(root->left, first);
    if (!*first) printf(" ");
    printf("%d", root->data);
    *first = 0;
    inorder(root->right, first);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    int first = 1;
    inorder(root, &first);
    printf("\n");

    return 0;
}
