/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    while (head != NULL) {
        struct Node* t = head;
        head = head->next;
        free(t);
    }
    
    return 0;
}