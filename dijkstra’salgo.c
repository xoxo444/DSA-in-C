#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF 1000000000
#define MAX 1005   


int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int V, int graph[MAX][MAX], int src) {
    int dist[MAX];     
    bool sptSet[MAX];      

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        if (u == -1) break; 
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t\t INF\n", i + 1);
        else
            printf("%d \t\t %d\n", i + 1, dist[i]);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    static int graph[MAX][MAX];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        if (w < graph[u][v])  
            graph[u][v] = w;  
    }

  
    int src;
    scanf("%d", &src);
    src--; 
    dijkstra(V, graph, src);
    return 0;
}
