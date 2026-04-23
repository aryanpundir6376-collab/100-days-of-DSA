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
int indegree[MAX];

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int v) {
    if(rear == MAX - 1) return;
    if(front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

int main() {
    int n, m, i, u, v;

    // Input vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize
    for(i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
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

        // increase indegree of v
        indegree[v]++;
    }

    // Add all vertices with indegree 0 to queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Process queue
    while(front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        count++;

        struct Node* temp = adj[current];

        while(temp != NULL) {
            indegree[temp->vertex]--;

            if(indegree[temp->vertex] == 0) {
                enqueue(temp->vertex);
            }

            temp = temp->next;
        }
    }

    // Check for cycle
    if(count != n) {
        printf("\nGraph contains a cycle (Topological sort not possible)\n");
    }

    return 0;
}