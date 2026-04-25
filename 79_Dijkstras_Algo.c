#include <stdio.h>
#define MAX 100
#define INF 9999

int graph[MAX][MAX];

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;   // remove this line if graph is directed
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int min = INF, u = -1;

        // Find minimum distance unvisited node
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        // Relax neighbors
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}