#include <stdio.h>
#include <limits.h>

#define MAX 100

// Edge structure
struct Edge {
    int u, v, w;
};

// Bellman-Ford Function
void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[MAX];

    // Step 1: Initialize distances
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Step 2: Relax edges (n-1 times)
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check negative cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 4: Print distances
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

// Main
int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(n, m, edges, src);

    return 0;
}