#include <stdio.h>

#define MAX 100

int main() {
    int n, m, i, u, v;
    int adj[MAX][MAX];

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Ask graph type
    int type;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &type);

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        // If undirected, mark both sides
        if(type == 0) {
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}