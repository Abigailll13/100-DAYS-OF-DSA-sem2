/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>

#include <stdio.h>

#define MAX 100

int visited[MAX];

void dfs(int adj[][MAX], int n, int v) {
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(adj, n, i);
        }
    }
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
    
    printf("DFS Traversal: ");
    dfs(adj, n, s);
    printf("\n");
    
    return 0;
}
