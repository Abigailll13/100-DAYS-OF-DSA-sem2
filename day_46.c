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
        if (i < n && arr[i] != -1) { parent->left = newNode(arr[i]); queue[rear++] = parent->left; }
        i++;
        if (i < n && arr[i] != -1) { parent->right = newNode(arr[i]); queue[rear++] = parent->right; }
        i++;
    }
    return root;
}

void printLevelOrder(Node* root) {
    if (!root) { printf("Empty tree\n"); return; }
    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left)  queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
    printf("\n");
}

int main() {
    // Test 1: Normal tree
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    int arr1[] = {1, 2, 3, 4, 5, -1, 6};
    Node* root1 = buildTree(arr1, 7);
    printf("Test 1: "); printLevelOrder(root1);  // Expected: 1 2 3 4 5 6

    // Test 2: -1 as null gaps
    //        1
    //       / \
    //      2   3
    //       \
    //        5
    int arr2[] = {1, 2, 3, -1, 5};
    Node* root2 = buildTree(arr2, 5);
    printf("Test 2: "); printLevelOrder(root2);  // Expected: 1 2 3 5

    // Test 3: Single node
    int arr3[] = {42};
    Node* root3 = buildTree(arr3, 1);
    printf("Test 3: "); printLevelOrder(root3);  // Expected: 42

    // Test 4: Empty tree
    int arr4[] = {-1};
    Node* root4 = buildTree(arr4, 1);
    printf("Test 4: "); printLevelOrder(root4);  // Expected: Empty tree

    return 0;
}