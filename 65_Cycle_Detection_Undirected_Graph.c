#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Node* adj[MAX];
int visited[MAX];

// DFS function for cycle detection
int dfs(int v, int parent) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int adjVertex = temp->vertex;

        if(!visited[adjVertex]) {
            if(dfs(adjVertex, v)) {
                return 1; // cycle found
            }
        }
        else if(adjVertex != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0; // no cycle
}

int main() {
    int n, m, i, u, v;

    // Input vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize
    for(i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int hasCycle = 0;

    // Check all components
    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    // Output result
    if(hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}