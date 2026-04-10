#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Min Heap structure
typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

// Swap
void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}

// Push to heap
void push(int node, int dist) {
    heap[heapSize].node = node;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Graph (Adjacency List)
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Add edge
void addEdge(int u, int v, int w) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->w = w;
    temp->next = adj[u];
    adj[u] = temp;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];
    
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}