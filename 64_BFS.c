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

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int v) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    if(front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// BFS function
void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while(front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adj[current];

        while(temp != NULL) {
            if(!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, i, u, v, s;

    // Input number of vertices
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

    int type;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &type);

    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        // u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // undirected
        if(type == 0) {
            newNode = createNode(u);
            newNode->next = adj[v];
            adj[v] = newNode;
        }
    }

    // Input source
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &s);

    // BFS traversal
    printf("BFS Traversal: ");
    bfs(s);

    return 0;
}