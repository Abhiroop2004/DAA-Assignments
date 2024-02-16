#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, v1, v2, w;
	int i, j;
	printf("Enter number of vertices for graph:");
	scanf("%d",&n);
	int* a[n];
	for (i = 0; i < n; i++)
		a[i] = (int*)malloc(n * sizeof(int));
	printf("Enter number of edges for graph:");
	scanf("%d",&m);
	printf("Enter edges of graph 0 to %d alongwith weight\n",n);
	for (i=0;i<m;i++)
	{
		scanf("%d %d %d",&v1, &v2, &w);
		a[v1][v2]=w;
		a[v2][v1]=w;
	}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
}
