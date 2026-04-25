#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];

void bfs(int n) {
    int queue[MAX];
    int front = 0, rear = 0;

    // Start from node 1
    queue[rear++] = 1;
    visited[1] = 1;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    bfs(n);

    // Check connectivity
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}