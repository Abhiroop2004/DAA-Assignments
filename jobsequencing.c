#include <stdio.h>
struct job
{
	int id,deadline;
	float profit;
};
void jobsequencing(struct job a[], int n)
{
	int i,j, max,t;
    float temp, profit=0.0;
    for (i=0;i<n;i++)
    {
        max=i;
        for (j=i;j<n;j++)
        {
            if (a[j].profit>a[max].profit)
                max=j;
        }
        int t1=a[i].id;
        int t2=a[i].deadline;
        float t3=a[i].profit;
        a[i].id=a[max].id;
        a[i].deadline=a[max].deadline;
        a[i].profit=a[max].profit;    
        a[max].id=t1;
        a[max].deadline=t2;
        a[max].profit=t3;
    }
    int result[n],slot[n];
    for(i=0;i<n;i++)
    	slot[i]=0;
    for (i=0;i<n;i++)
    {
    	for (j=a[i].deadline-1;j>=0;j--)
    	{
    		if (slot[j]==0)
    		{
    			slot[j]=1;
    			result[j]=i;
    			profit+=a[i].profit;
    			break;
    		}
    	}
    }
    printf("\nTotal Profit: %.2f",profit);
    printf("\nJob Sequence: ");
    for (i=0;i<n;i++)
      if (slot[i]==1)
         printf("%d, ", a[result[i]].id);
}
int main()
{
	int n;
	printf("Enter no. of jobs: ");
	scanf("%d",&n);
	struct job a[n];
	for (int i=0;i<n;i++)
	{
		printf("Details of job %d (deadline slot and profit): ",i+1);
		a[i].id=i+1;
		scanf("%d %f",&a[i].deadline,&a[i].profit);
	}
	jobsequencing(a,n);
}