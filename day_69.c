/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// ─── Min-Heap (Priority Queue) ───────────────────────────────────────────────

typedef struct {
    int vertex, dist;
} Node;

typedef struct {
    Node data[MAX_VERTICES];
    int size;
} MinHeap;

void swap(Node *a, Node *b) { Node t = *a; *a = *b; *b = t; }

void push(MinHeap *h, int vertex, int dist) {
    int i = h->size++;
    h->data[i] = (Node){vertex, dist};
    while (i > 0 && h->data[(i-1)/2].dist > h->data[i].dist) {
        swap(&h->data[(i-1)/2], &h->data[i]);
        i = (i-1)/2;
    }
}

Node pop(MinHeap *h) {
    Node top = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (true) {
        int smallest = i, l = 2*i+1, r = 2*i+2;
        if (l < h->size && h->data[l].dist < h->data[smallest].dist) smallest = l;
        if (r < h->size && h->data[r].dist < h->data[smallest].dist) smallest = r;
        if (smallest == i) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return top;
}

// ─── Graph (Adjacency List) ───────────────────────────────────────────────────

typedef struct Edge { int to, weight, next; } Edge;

Edge edges[MAX_VERTICES * MAX_VERTICES];
int head[MAX_VERTICES];   // head[u] = index of first edge from u
int edgeCount = 0;

void addEdge(int u, int v, int w) {
    edges[edgeCount] = (Edge){v, w, head[u]};
    head[u] = edgeCount++;
}

// ─── Dijkstra ────────────────────────────────────────────────────────────────

int  dist[MAX_VERTICES];
bool visited[MAX_VERTICES];

void dijkstra(int src, int n) {
    for (int i = 0; i < n; i++) dist[i] = INT_MAX, visited[i] = false;
    dist[src] = 0;

    MinHeap pq = {.size = 0};
    push(&pq, src, 0);

    while (pq.size > 0) {
        Node cur = pop(&pq);
        int u = cur.vertex;

        if (visited[u]) continue;
        visited[u] = true;

        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to, w = edges[e].weight;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&pq, v, dist[v]);
            }
        }
    }
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    int n, m, src;
    printf("Vertices, Edges, Source: ");
    scanf("%d %d %d", &n, &m, &src);

    for (int i = 0; i < n; i++) head[i] = -1;   // init adjacency list

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);   // remove for directed graph
    }

    dijkstra(src, n);

    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("  %d → %d : unreachable\n", src, i);
        else
            printf("  %d → %d : %d\n", src, i, dist[i]);
    }
    return 0;
}