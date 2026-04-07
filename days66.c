#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// DFS function to detect cycle
bool dfs(int node, int** graph, int* graphColSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, graphColSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // allocate graph
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphColSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(MAX * sizeof(int));
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][graphColSize[u]++] = v; // directed edge u → v
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool* recStack = (bool*)calloc(n, sizeof(bool));

    // check cycle
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, graphColSize, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}