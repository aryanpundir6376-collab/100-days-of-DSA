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

// Stack for topological order
int stack[MAX];
int top = -1;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(v);
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

    printf("Enter directed edges (u v):\n");
    for(i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // Call DFS for all vertices (handles disconnected graph)
    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order (reverse of stack)
    printf("Topological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}