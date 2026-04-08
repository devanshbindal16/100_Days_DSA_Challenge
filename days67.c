#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int* adjCount = (int*)calloc(numCourses, sizeof(int));

    // Step 1: Count edges for each node
    for(int i = 0; i < prerequisitesSize; i++) {
        adjCount[prerequisites[i][1]]++;
    }

    // Step 2: Allocate adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for(int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(adjCount[i] * sizeof(int));
        adjCount[i] = 0; // reset for reuse
    }

    // Step 3: Build graph
    for(int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjCount[b]++] = a;
        indegree[a]++;
    }

    // Step 4: Queue
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 5: Topological Sort
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    while(front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for(int i = 0; i < adjCount[node]; i++) {
            int neigh = adj[node][i];
            indegree[neigh]--;

            if(indegree[neigh] == 0) {
                queue[rear++] = neigh;
            }
        }
    }

    // Step 6: Check cycle
    if(count != numCourses) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = count;
    return result;
}