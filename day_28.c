/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

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
        newNode->next = *head; // Point to itself to make it circular
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) { // Traverse until we reach the last node
        temp = temp->next;
    }
    temp->next = newNode; // Point last node to new node
    newNode->next = *head; // Point new node to head to maintain circular structure
}
void printCircularList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Loop until we return to head
}
int main() {
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        appendNode(&head, data);
    }
    printCircularList(head);
    return 0;
}
