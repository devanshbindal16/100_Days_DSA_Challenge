#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// Function for Topological Sort using Kahn's Algorithm
void topologicalSort() {
    int i, j, count = 0;

    // Step 1: Initialize indegree array
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Step 2: Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 3: Insert all vertices with indegree 0 into queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("\nTopological Order: ");

    // Step 4: Process queue
    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 5: Check for cycle
    if (count != n) {
        printf("\nGraph contains a cycle. Topological sort not possible.\n");
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}