#include <stdio.h>

int reached[13];
int adj[13][13];
int n;
void dfs(int v)
{
    int i;
    reached[v]=1;
    for (i = 1; i <= n; i++)
    {
        if (adj[v][i] && !reached[i]) 
        {
            printf("    %d", i);
            dfs(i);
        }
    }
}

int visited[12], queue[12];
int front = 0, rear = -1;

void dequeue()
{
    int e = queue[front++];
    printf("%d  ",e);
}
void enqueue(int a)
{
    queue[++rear]=a;
    visited[a]=1;
}
void bfs(int v)
{
    int i;
    for (i = 1; i <=n; i++)
        if (adj[v][i] && !visited[i])
            enqueue(i);
    if (front <= rear)
    {   
        int next=queue[front];
        dequeue(); 
        bfs(next);
    }
}
int main() 
{
    int i, j, v, c;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting vertex: \n");
    scanf("%d", &v);

    printf("Enter 1 for BFS, 2 for DFS: ");
    scanf("%d", &c);

    printf("Visited:\n");
    printf("%d  ", v);

    if (c == 2) 
    {
        for (i = 1; i <= n; i++)
            reached[i] = 0;
        dfs(v);
    } 
    else if (c == 1) 
    {
        for (i = 1; i <= n; i++) 
        {
            queue[i] = 0;
            visited[i] = 0;
        }
        visited[v] = 1;
        bfs(v);
    } 
    else 
        printf("Wrong Choice!");
    return 0;
}
