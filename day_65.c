/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>

#define MAX 100

int visited[MAX];

int dfs(int adj[][MAX], int n, int v, int parent) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1) {
            if (!visited[i]) {
                // Recurse on unvisited neighbor
                if (dfs(adj, n, i, v))
                    return 1;
            }
            // Visited neighbor that is NOT parent → cycle found
            else if (i != parent)
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected
    }

    int hasCycle = 0;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, n, i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    printf("%s\n", hasCycle ? "YES" : "NO");
    return 0;
}