#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Node* adj[MAX];
int visited[MAX];

// DFS function (recursive)
void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m, i, u, v, s;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for(i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Graph type
    int type;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &type);

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // If undirected
        if(type == 0) {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }

    // Input starting vertex
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &s);

    // Perform DFS
    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}