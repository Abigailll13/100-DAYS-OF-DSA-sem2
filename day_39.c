/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("-1\n");
        return;
    }
    heap->data[heap->size] = value;
    int current = heap->size;
    heap->size++;

    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap->data[current] < heap->data[parent]) {
            swap(&heap->data[current], &heap->data[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

int extractMin(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    int min = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    int current = 0;
    while (current < heap->size) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;

        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }
        if (smallest != current) {
            swap(&heap->data[current], &heap->data[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
    return min;
}

int peek(MinHeap *heap) {
    if (heap->size == 0) {
        return -1;
    }
    return heap->data[0];
}

int main() {
    MinHeap heap;
    heap.size = 0;

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char operation[10];
        scanf("%s", operation);
        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);
            insert(&heap, value);
        } else if (strcmp(operation, "extractMin") == 0) {
            printf("%d\n", extractMin(&heap));
        } else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek(&heap));
        }
    }
    return 0;
}