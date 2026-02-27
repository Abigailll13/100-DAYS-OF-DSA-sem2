
/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/


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
    temp->next = newNode;
}

int listsMatch(Node* a, Node* b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data) return 0;
        a = a->next;
        b = b->next;
    }
    return (b == NULL); // all of b matched, list1 may have extra nodes — that's fine
}

Node* findIntersection(Node* head1, Node* head2) {
    for (Node* p1 = head1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = head2; p2 != NULL; p2 = p2->next) {
            if (listsMatch(p1, p2)) {
                return p1;
            }
        }
    }
    return NULL;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n, m, val;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        appendNode(&list1, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        appendNode(&list2, val);
    }

    Node* intersection = findIntersection(list1, list2);

    if (intersection != NULL) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    freeList(list1);
    freeList(list2);

    return 0;
}
