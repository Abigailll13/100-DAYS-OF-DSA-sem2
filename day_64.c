/*Problem: Perform BFS starting from a given source vertex.

Input:
- n
- adjacency list
- starting vertex s

Output:
- BFS traversal order*/

#include <stdio.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// BFS function
void bfs(int adj[][MAX], int n, int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, s;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    bfs(adj, n, s);

    return 0;
}