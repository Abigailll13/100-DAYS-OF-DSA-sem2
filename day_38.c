/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
};
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    return deque;
}
void push_front(struct Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = deque->front;
    newNode->prev = NULL;
    if (deque->front != NULL) {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
    if (deque->rear == NULL) {
        deque->rear = newNode;
    }
    deque->size++;
}
void push_back(struct Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (deque->rear != NULL) {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
    if (deque->front == NULL) {
        deque->front = newNode;
    }
    deque->size++;
}
void pop_front(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }
    free(temp);
    deque->size--;
}
void pop_back(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }
    free(temp);
    deque->size--;
}
int front(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return -1; // Return -1 to indicate empty deque
    }
    return deque->front->data;
}
int back(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty\n");
        return -1; // Return -1 to indicate empty deque
    }
    return deque->rear->data;
}
int empty(struct Deque* deque) {
    return deque->size == 0;
}
int size(struct Deque* deque) {
    return deque->size;
}
void clear(struct Deque* deque) {
    while (!empty(deque)) {
        pop_front(deque);
    }
}
void display(struct Deque* deque) {
    struct Node* temp = deque->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Deque* deque = createDeque();
    push_back(deque, 10);
    push_back(deque, 20);
    push_front(deque, 5);
    printf("Front: %d\n", front(deque));
    printf("Back: %d\n", back(deque));
    printf("Size: %d\n", size(deque));
    display(deque);
    pop_front(deque);
    pop_back(deque);
    printf("After popping front and back:\n");
    display(deque);
    clear(deque);
    printf("After clearing the deque:\n");
    display(deque);
    free(deque);
    return 0;
}
