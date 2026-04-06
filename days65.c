#include <stdio.h>
#include <stdbool.h>

int adj[100][100];
bool visited[100];

// DFS function
bool dfs(int node, int parent, int n) {
    visited[node] = true;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return true;
            } 
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // check cycle
    int hasCycle = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}