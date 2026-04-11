#include <stdio.h>
#include <limits.h>

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;

    // Input number of vertices and edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    Edge edges[m];

    // Input edges
    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[n];

    // Step 1: Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Relax edges (n-1 times)
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("\nNEGATIVE WEIGHT CYCLE DETECTED\n");
            return 0;
        }
    }

    // Step 4: Print shortest distances
    printf("\nShortest distances from source %d:\n", src);
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}