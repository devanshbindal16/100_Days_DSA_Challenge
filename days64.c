#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    struct Node* adj[MAX];
    int visited[MAX];
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(struct Graph* g, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = g->adj[u];
    g->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

// BFS function
void BFS(struct Graph* g, int n, int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    // Mark start as visited and enqueue
    g->visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = g->adj[curr];

        while (temp) {
            int adjNode = temp->data;

            if (!g->visited[adjNode]) {
                g->visited[adjNode] = 1;
                queue[rear++] = adjNode;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));

    // Initialize
    for (int i = 0; i < n; i++) {
        g->adj[i] = NULL;
        g->visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(g, n, s);

    return 0;
}