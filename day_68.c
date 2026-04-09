/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>

#define MAX 100

int main() {
    int n, m; // n = nodes, m = edges
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], index = 0;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v means u -> v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Step 1: push nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 2: process queue
    while(front < rear) {
        int node = queue[front++];
        topo[index++] = node;

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check for cycle
    if(index != n) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}