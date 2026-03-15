/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Stack {
    struct Node* top;
};
void push(struct Stack* s, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = s->top;
    s->top = temp;
}
int pop(struct Stack* s) {
    if (s->top == NULL) {
        return -1; // Stack is empty
    }
    struct Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}
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
int main() {
    int N;
    scanf("%d", &N);
    struct Queue q = {NULL, NULL};
    struct Stack s = {NULL};
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&q, value);
    }
    while (q.front != NULL) {
        push(&s, q.front->data);
        q.front = q.front->next;
    }
    while (s.top != NULL) {
        printf("%d ", pop(&s));
    }
    return 0;
}
