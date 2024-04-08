#include <stdio.h>  
#include <stdlib.h> 
#include <limits.h>
#define MAX 10  

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) 
{  
  int cost[MAX][MAX], distance[MAX], previous[MAX];  
  int visited_nodes[MAX], counter, minimum_distance, next_node, i, j;  
  
  for (i = 0; i < size; i++)  
    for (j = 0; j < size; j++)  
      if (Graph[i][j] == 0)  
        cost[i][j] = INT_MAX;  
      else  
        cost[i][j] = Graph[i][j];  
  
  for (i = 0; i < size; i++) 
  {  
    distance[i] = cost[start][i];  
    previous[i] = start;  
    visited_nodes[i] = 0;  
  }  
  
  distance[start] = 0;  
  visited_nodes[start] = 1;  
  counter = 1;  
  
  while (counter < size - 1) {  
    minimum_distance = INT_MAX;  
  
    for (i = 0; i < size; i++)  
      if (distance[i] < minimum_distance && !visited_nodes[i]) {  
        minimum_distance = distance[i];  
        next_node = i;  
      }  
  
    visited_nodes[next_node] = 1;  
    for (i = 0; i < size; i++)   
      if (!visited_nodes[i])  
        if (minimum_distance + cost[next_node][i] < distance[i]) {  
          distance[i] = minimum_distance + cost[next_node][i];  
          previous[i] = next_node;  
        }  
    counter++;  
  }  

  for (i = 0; i < size; i++)  
    if (i != start) {  
      printf("\nDistance from the Source Node to %d: %d", i, distance[i]);  
    }  
}  

int main() {
    int v, e, v1, v2, w;
    int **graph;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    graph = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        graph[i] = (int *)malloc(v * sizeof(int));
    }
    printf("Enter number of edges for graph:");
    scanf("%d", &e);
    printf("Enter edges of graph 0 to %d along with weight\n", v - 1);
    for (int i = 0; i < e; i++)
    {
      scanf("%d %d %d", &v1, &v2, &w);
      graph[v1][v2] = w;
      graph[v2][v1] = w;
    } 
    int start;
    printf("Enter the start vertex: ");
    scanf("%d", &start);

    DijkstraAlgorithm(graph, v, start);

    for (int i = 0; i < v; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
