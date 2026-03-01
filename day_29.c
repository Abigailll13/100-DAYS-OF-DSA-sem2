/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Point last node to new node
}
void rotateRight(Node** head, int k) {
    if (*head == NULL || k == 0) return;
    Node* temp = *head;
    int length = 1; // Calculate length of the list
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }
    temp->next = *head; // Connect last node to head to form circular list
    k = k % length; // Handle cases where k >= length
    for (int i = 0; i < length - k; i++) {
        temp = temp->next; // Move to (n-k)th node
    }
    *head = temp->next; // Update head to (n-k+1)th node
    temp->next = NULL; // Break the circular link
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        appendNode(&head, data);
    }
    scanf("%d", &k);
    rotateRight(&head, k);
    printList(head);
    return 0;
}