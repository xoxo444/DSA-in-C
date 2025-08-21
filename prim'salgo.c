#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF 1000000000

int minKey(int V, int key[], bool inMST[]) {
    int min = INF, min_idx = -1;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_idx = v;
        }
    }
    return min_idx;
}

int main(void) {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    static int adj[1005][1005]; 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        if (w < adj[u][v]) {            
            adj[u][v] = adj[v][u] = w;  
        }
    }

    int parent[1005]; 
    int key[1005];      
    bool inMST[1005];   

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int u = minKey(V, key, inMST);
        if (u == -1) break;         
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    long long total = 0;
    for (int v = 1; v < V; v++) {
        if (parent[v] == -1) {
            printf("Graph is disconnected; MST not possible.\n");
            return 0;
        }
        total += adj[parent[v]][v];
    }

    printf("Edges in MST (u v w):\n");
    for (int v = 1; v < V; v++) {
        printf("%d %d %d\n", parent[v] + 1, v + 1, adj[parent[v]][v]);
    }
    printf("Total weight: %lld\n", total);
    return 0;
}
