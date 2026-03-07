/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if (rear < MAX_SIZE - 1) {
        rear++;
        queue[rear] = value;
        if (front == -1) {
            front = 0; // First element enqueued
        }
    }
}
void dequeue() {
    if (front != -1) {
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue when empty
        }
    }
}
void display() {
    if (front != -1) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Queue elements: ");
    display();
    return 0;
}
