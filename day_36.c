/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE != front) { // Check for full queue
        rear = (rear + 1) % MAX_SIZE; // Move rear pointer
        queue[rear] = value; // Insert value
        if (front == -1) {
            front = 0; // First element enqueued
        }
    }
}
void dequeue() {
    if (front != -1) { // Check for empty queue
        front = (front + 1) % MAX_SIZE; // Move front pointer
        if (front == (rear + 1) % MAX_SIZE) { // Queue becomes empty
            front = rear = -1; // Reset pointers
        }
    }
}
void display() {
    if (front != -1) {
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE; // Move to next index
        }
        printf("%d\n", queue[rear]); // Print rear element
    }
}
int main() {
    int n, m;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue();
    }
    printf("Queue elements after operations: ");
    display();
    return 0;
}
