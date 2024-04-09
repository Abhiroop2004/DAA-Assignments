#include <stdio.h>
#define MAX 999  

void BellmanFord(int graph[][3], int size, int e, int start) 
{
    int distance[size];
    int i, j;
    for (i = 0; i < size; i++)
        distance[i] = MAX;
    distance[start] = 0;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < e; j++) {
            if (distance[graph[j][0]] != MAX && distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]])
                distance[graph[j][1]] = distance[graph[j][0]] + graph[j][2];
        }
    }
    for (i = 0; i < e; i++) {
        if (distance[graph[i][0]] != MAX && distance[graph[i][0]] + graph[i][2] < distance[graph[i][1]])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printf("Vertex Distance from Source\n");
    for (i = 0; i < size; i++)
        printf("%d\t\t%d\n", i, distance[i]);
} 

int main() {
    int v, e, v1, v2, w, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges for graph:");
    scanf("%d", &e);
    int graph[e*2][3];
    printf("Enter edges of graph 1 to %d along with weight\n", v);
    for (i = 0; i < e*2; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        graph[i][0] = v1 - 1;
        graph[i][1] = v2 - 1;
        graph[i][2] = w;
    } 
    for (i = 0; i < e; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    int start;
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    BellmanFord(graph, v, 2*e, start - 1);
    return 0;
}
