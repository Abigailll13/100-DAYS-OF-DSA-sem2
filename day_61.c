/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

void initGraph() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
}

void addEdgeUndirected(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void addEdgeDirected(int u, int v) {
    graph[u][v] = 1;
}

void display() {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < n; i++) printf("%3d", i);
    printf("\n");
    printf("   ");
    for (int i = 0; i < n; i++) printf("---");
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%2d|", i);
        for (int j = 0; j < n; j++)
            printf("%3d", graph[i][j]);
        printf("\n");
    }
}

int main() {
    int choice;

    printf("--- Graph Builder ---\n");
    printf("1. Undirected Graph\n");
    printf("2. Directed Graph\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice!\n");
        return 0;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    initGraph();

    printf("Enter %d edges (u v) [0-indexed]:\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge (%d, %d)! Skipping.\n", u, v);
            i--;
            continue;
        }

        if (choice == 1) addEdgeUndirected(u, v);
        else             addEdgeDirected(u, v);
    }

    display();

    return 0;
}
