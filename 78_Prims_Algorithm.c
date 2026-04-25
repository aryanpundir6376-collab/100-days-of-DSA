#include <stdio.h>
#define MAX 100
#define INF 9999

int graph[MAX][MAX];
int visited[MAX];

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
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
        graph[v][u] = w;   // undirected
    }

    int total = 0;
    visited[1] = 1;  // start from node 1

    for (int k = 1; k < n; k++) {
        int min = INF, u = -1, v = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            visited[v] = 1;
            total += min;
        }
    }

    printf("Total weight of MST: %d\n", total);

    return 0;
}