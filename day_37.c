/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20, ask users for input*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int size = 0;
void insert(int value) {
    if (size < MAX_SIZE) {
        queue[size] = value;
        size++;
    }
}
void delete() {
    if (size > 0) {
        int min_index = 0;
        for (int i = 1; i < size; i++) {
            if (queue[i] < queue[min_index]) {
                min_index = i;
            }
        }
        printf("%d\n", queue[min_index]);
        for (int i = min_index; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
    } else {
        printf("-1\n");
    }
}
void peek() {
    if (size > 0) {
        int min_index = 0;
        for (int i = 1; i < size; i++) {
            if (queue[i] < queue[min_index]) {
                min_index = i;
            }
        }
        printf("%d\n", queue[min_index]);
    } else {
        printf("-1\n");
    }
}
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char operation[10];
        int value;
        printf("Enter operation: ");
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        } else if (strcmp(operation, "delete") == 0) {
            delete();
        } else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }
    return 0;
}