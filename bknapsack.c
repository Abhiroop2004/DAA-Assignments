#include <stdio.h>

void swap(int* a, int* b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition2(int a[][2], int begin, int end) 
{
    int pivot = a[end][1];
    int j = begin;  
    for (int i = begin; i <= end - 1; i++) 
    {
        if (a[i][1] < pivot) 
        {
            swap(&a[j][0],&a[i][0]);
            swap(&a[j][1],&a[i][1]);
            j++;
        }
    }
    swap(&a[j][0],&a[end][0]);
    swap(&a[j][1],&a[end][1]);
    return (j);
}

void quickSort2(int a[][2], int start, int end)
{
    if (start >= end) return;
    int p = partition2(a, start, end);  
    quickSort2(a, start, p - 1);
    quickSort2(a, p + 1, end);
}

int maximum(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

void bknapsack(int a[][2],int w, int n)
{
 int i,j;
 int m[n+1][w+1];
 quickSort2(a,0,n-1);
 for (i=0;i<n;i++)
    printf("%d  %d \n",a[i][0],a[i][1]);
 for (i=0;i<=n;i++)
 {
 	for (j=0;j<=w;j++)
 	{
        if (i==0 || j==0)
            m[i][j]=0;
 		else if (a[i-1][1]<=j)
            m[i][j]=maximum(m[i-1][j], m[i-1][j-a[i-1][1]]+a[i-1][0]);
        else
            m[i][j]=m[i-1][j];
 	}
 }
 int p=m[n][w];
 printf("Total Profit:  %d\n",p);
 j=w;
 printf("Weights of Items included: ");
 for (i=n;i>=0 && p>0;i--)
 {  
    if (m[i-1][j]==p)
        continue;
    printf("%d  ",a[i-1][1]);
    p-=a[i-1][0];
    w-=a[i-1][1];
 }
}

int main()
{
	int i,n;
    int w;
    printf("Enter number of objects:\n");
    scanf("%d",&n);
    int a[n][2];
    printf("Enter details of object\n");
    for (i=0;i<n;i+=1)
    {
        printf("Details for %d:\n",i+1);
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    printf("Enter total weight:\n");
    scanf("%d",&w);
    bknapsack( a, w, n);
}