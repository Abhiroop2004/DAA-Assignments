#include <stdio.h>  
#include <stdlib.h> 
#define MAX 99  

int mindistance(int distance[], int included[], int size)
{
  int min= MAX, minindex;
  for ( int i=0; i< size; i++)
    if (included[i]==0 && distance[i]<= min)
    {
      min= distance[i]; minindex= i;
    }
  return minindex;
}

void DijkstraAlgorithm(int Graph[][10], int size, int start) 
{  
  int distance[size];
  int included[size];
  int i, j;
  for (i=0; i< size; i++)
  {
    if (Graph[start][i]!=0) distance[i]=Graph[start][i]; else distance[i] = MAX;
    included[i] = 0;
  }
  distance[start]=0;
  for (i=0; i< size-1; i++)
  {
    int t= mindistance(distance, included, size);
    included[t]=1;
    for (j=0; j < size; j++)
      if (included[i]==0 && Graph[t][j] && distance[t] != MAX && distance[t] + Graph[t][j] < distance[j])
        distance[j]= distance[t] + Graph[t][j];
  }
  for (i = 0; i < size; i++)  
    if (i != start) 
    {  
      printf("\nDistance from the %d to %d = %d", start+1, i+1, distance[i]);  
    } 
}  

int main() 
{
    int v, e, v1, v2, w, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int graph[v][v];
    for (i = 0; i < v; i++) {
      for(j=0; j<v; j++) 
        graph[i][j] = 0;
    }
    printf("Enter number of edges for graph:");
    scanf("%d", &e);
    printf("Enter edges of graph with verrtices 1 to %d along with weight\n", v);
    for (int i = 0; i < e; i++)
    {
      scanf("%d %d %d", &v1, &v2, &w);
      graph[v1-1][v2-1] = w;
      graph[v2-1][v1-1] = w;
    } 
    for (i=0; i<v; i++)
    {
      for (j=0; j<v; j++)
      {
        printf("%d ",graph[i][j]);
      }
      printf("\n");
    }
    int start;
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    DijkstraAlgorithm(graph, v, start-1);
}
