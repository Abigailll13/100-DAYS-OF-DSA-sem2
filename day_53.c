/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

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


#define MAX_NODES 1000

typedef struct {
    Node* node;
    int hd;
} QueueItem;

// Store nodes grouped by horizontal distance
int    hdValues[MAX_NODES];       // hd of each stored node
int    nodeValues[MAX_NODES];     // value of each stored node
int    count = 0;

void verticalOrder(Node* root) {
    if (root == NULL) return;

    QueueItem queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = (QueueItem){root, 0};

    while (front < rear) {
        QueueItem curr = queue[front++];
        Node* node     = curr.node;
        int   hd       = curr.hd;

        // Store this node
        hdValues[count]   = hd;
        nodeValues[count] = node->data;
        count++;

        if (node->left)  queue[rear++] = (QueueItem){node->left,  hd - 1};
        if (node->right) queue[rear++] = (QueueItem){node->right, hd + 1};
    }
}

void printVertical() {
    // Find min and max hd
    int minHd = hdValues[0], maxHd = hdValues[0];
    for (int i = 1; i < count; i++) {
        if (hdValues[i] < minHd) minHd = hdValues[i];
        if (hdValues[i] > maxHd) maxHd = hdValues[i];
    }

    // Print column by column
    for (int hd = minHd; hd <= maxHd; hd++) {
        int printed = 0;
        for (int i = 0; i < count; i++) {
            if (hdValues[i] == hd) {
                if (printed) printf(" ");
                printf("%d", nodeValues[i]);
                printed = 1;
            }
        }
        if (printed) printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_NODES];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    verticalOrder(root);
    printVertical();

    return 0;
}