/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    scanf("%d %d", &n, &m);

    // initialize matrix with large value
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    visited[1] = 1;  // start from node 1
    int edges = 0;
    int total_weight = 0;

    while (edges < n - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && adj[i][j] < min) {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            visited[v] = 1;
            total_weight += min;
            edges++;
        }
    }

    printf("%d\n", total_weight);

    return 0;
}