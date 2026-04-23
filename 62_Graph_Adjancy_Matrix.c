#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, i, u, v;

    struct Node* adj[MAX];  // array of adjacency lists

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency lists
    for(i = 0; i < n; i++) {
        adj[i] = NULL;
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

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // If undirected, add v -> u also
        if(type == 0) {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for(i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];

        while(temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}