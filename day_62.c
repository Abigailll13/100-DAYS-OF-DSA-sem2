/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/

#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;


typedef struct {
    AdjNode** list;   // array of linked lists
    int n;
} Graph;

Graph* createGraph(int n) {
    Graph* g  = (Graph*)malloc(sizeof(Graph));
    g->n      = n;
    g->list   = (AdjNode**)malloc(n * sizeof(AdjNode*));
    for (int i = 0; i < n; i++)
        g->list[i] = NULL;
    return g;
}

AdjNode* newAdjNode(int v) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->vertex  = v;
    node->next    = NULL;
    return node;
}

void addEdgeUndirected(Graph* g, int u, int v) {
    // add v to u's list
    AdjNode* node   = newAdjNode(v);
    node->next      = g->list[u];
    g->list[u]      = node;

    // add u to v's list
    node            = newAdjNode(u);
    node->next      = g->list[v];
    g->list[v]      = node;
}

void addEdgeDirected(Graph* g, int u, int v) {
    // add v to u's list only
    AdjNode* node   = newAdjNode(v);
    node->next      = g->list[u];
    g->list[u]      = node;
}

void display(Graph* g) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < g->n; i++) {
        printf("  %d -> ", i);
        AdjNode* curr = g->list[i];
        while (curr != NULL) {
            printf("%d", curr->vertex);
            if (curr->next) printf(" -> ");
            curr = curr->next;
        }
        printf(" NULL\n");
    }
}

// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main() {
    int choice, n, m;

    printf("--- Graph Builder (Adjacency List) ---\n");
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

    Graph* g = createGraph(n);

    printf("Enter %d edges (u v) [0-indexed]:\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge (%d, %d)! Skipping.\n", u, v);
            i--;
            continue;
        }

        if (choice == 1) addEdgeUndirected(g, u, v);
        else             addEdgeDirected(g, u, v);
    }

    display(g);

    return 0;
}