#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for(int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* pq, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist)
        smallest = left;

    if(right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

// Push into heap
void push(struct MinHeap* pq, int v, int dist) {
    int i = pq->size++;
    pq->heap[i].vertex = v;
    pq->heap[i].dist = dist;

    while(i != 0 && pq->heap[(i-1)/2].dist > pq->heap[i].dist) {
        swap(&pq->heap[i], &pq->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Pop min
struct HeapNode pop(struct MinHeap* pq) {
    struct HeapNode root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapify(pq, 0);
    return root;
}

// Dijkstra Algorithm
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    struct MinHeap pq;
    pq.size = 0;

    // Initialize distances
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(&pq, src, 0);

    while(pq.size > 0) {
        struct HeapNode minNode = pop(&pq);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];

        while(temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&pq, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    return 0;
}