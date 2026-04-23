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
int recStack[MAX];

// DFS function
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        int adjVertex = temp->vertex;

        // If not visited, recurse
        if(!visited[adjVertex]) {
            if(dfs(adjVertex))
                return 1;
        }
        // If already in recursion stack → cycle
        else if(recStack[adjVertex]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
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
        recStack[i] = 0;
    }

    // Input edges
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter directed edges (u v):\n");
    for(i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // u -> v (directed)
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int hasCycle = 0;

    // Check all vertices
    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    // Output
    if(hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}