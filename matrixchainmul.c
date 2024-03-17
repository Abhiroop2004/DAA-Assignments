#include <stdio.h>
#include <limits.h>
void mcm(int d[], int n)
{
	int l,i,j,k,mink;
	int cost[n][n];
	int parenthesis[n-1][n-1];
	for (i=0;i<n;i++)
		cost[i][i]=0;
	for (l=1;l<n;l++)
	{
		for (i=0;i<n-l;i++)
		{	
			j=i+l,mink=0;
			int minCost=INT_MAX;
			for(k=i; k<j; k++)
			{
				int currentCost=cost[i][k]+(d[i]*d[k+1]*d[j+1])+cost[k+1][j];
				if(currentCost<minCost)		{minCost=currentCost; mink=k+1;}
			}
			cost[i][j]=minCost;
			parenthesis[i][j-1]=mink;
		}
	}
	printf("Min Cost= %d\n",cost[0][n-1]);
	printf("Cost Matrix= \n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (i<=j)	printf("%d\t",cost[i][j]);
			else printf("\t");
		printf("\n");
	}
	printf("Parenthesis Matrix= \n");
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<n-1;j++)
			if (i<=j)	printf("%d\t",parenthesis[i][j]);
			else printf("\t");
		printf("\n");
	}
}
int main()
{
	int n,t1,t2,i=0;
	printf("Enter no. of matrices: ");
	scanf("%d",&n);
	int a[n+1];
	printf("Enter dimensions of matrix %d : ",i+1);
	scanf("%d",&a[0]);
	scanf("%d",&a[1]);
	for (i=2;i<=n;i++)
	{
		printf("Enter dimensions of matrix %d : ",i);
		scanf("%d",&t1);
		scanf("%d",&t2);
		if (t1==a[i-1])
			a[i]=t2;
		else
			printf("Error!\n");
	}	
	mcm(a,n);
}
