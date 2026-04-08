/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node* adjList[MAX];
};

int stack[MAX];
int top = -1;
int visited[MAX];

// Create a new adjacency list node
struct Node* newNode(int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

// Add directed edge u -> v
void addEdge(struct Graph* g, int u, int v) {
    struct Node* node = newNode(v);
    node->next = g->adjList[u];
    g->adjList[u] = node;
}

// DFS + push to stack after visiting all neighbors
void dfs(struct Graph* g, int v) {
    visited[v] = 1;

    struct Node* temp = g->adjList[v];
    while (temp) {
        if (!visited[temp->dest])
            dfs(g, temp->dest);
        temp = temp->next;
    }

    // Push current vertex to stack AFTER all descendants are processed
    stack[++top] = v;
}

// Topological Sort
void topoSort(struct Graph* g) {
    for (int i = 0; i < g->vertices; i++)
        visited[i] = 0;

    for (int i = 0; i < g->vertices; i++)
        if (!visited[i])
            dfs(g, i);

    // Print stack in reverse (top to bottom = topo order)
    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    struct Graph g;
    g.vertices = 6;

    for (int i = 0; i < g.vertices; i++)
        g.adjList[i] = NULL;

    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);

    topoSort(&g);
    return 0;
}