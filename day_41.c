/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1; // Queue is empty
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    }
    free(temp);
    return value;
}
int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    int N, operation, value;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &operation);
        if (operation == 1) { // Enqueue
            scanf("%d", &value);
            enqueue(&q, value);
        } else if (operation == 2) { // Dequeue
            int result = dequeue(&q);
            printf("%d\n", result);
        }
    }
    return 0;
}
