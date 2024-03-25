#include <stdio.h>
#include <limits.h>

void floyd(int n, int distance[][n]) 
{
    int i, j, k;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
            if (distance[i][j] == INT_MAX)  printf("INF ");
            else  printf("%d ", distance[i][j]);
        printf("\n");
    }
}

int main() 
{
    int i,j,n,m,w,v1,v2;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter number of edges:");
    scanf("%d",&m);
    int a[n][n];
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=n;j++)
            if (i==j)   a[i][j]=0;
            else a[i][j]=INT_MAX;
    }
    printf("Enter edges of graph from v1 to v2 alongwith weight\n");
    for (i=0;i<m;i++)
    {
        scanf("%d %d %d",&v1, &v2, &w);
        a[v1-1][v2-1]=w;
    }
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if (a[i][j] == INT_MAX)   printf("INF ");
            else printf("%d  ",a[i][j]);
        printf("\n");
    }      
    printf("All Pair Shortest Path:\n");  
    floyd(3, a);
};
}
