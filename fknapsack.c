#include <stdio.h>

float knapsack(float a[][3], int n, float wt)
{
    int i,j, max,t;
    float temp, profit=0.0;
    for (i=0;i<n;i++)
    {
        max=i;
        for (j=i;j<n;j++)
        {
            if (a[j][2]>a[max][2])
                max=j;
        }

        temp=wt-a[max][1];
        if (temp<0)
        {
            profit+=(wt*a[max][2]);
            wt=0;
        }
        else
        {
            wt=temp;
            profit+=a[max][0];
        }
        if (wt==0)
            return profit;

        float t1=a[i][0];
        float t2=a[i][1];
        float t3=a[i][2];
        a[i][0]=a[max][0];
        a[i][1]=a[max][1];
        a[i][2]=a[max][2];    
        a[max][0]=t1;
        a[max][1]=t2;
        a[max][2]=t3;
    }
}
int main()
{
    int i,n;
    float w;
    printf("Enter number of objects:\n");
    scanf("%d",&n);
    float a[n][3];
    printf("Enter details of object\n");
    for (i=0;i<n;i+=1)
    {
        printf("Details for %d:\n",i+1);
        scanf("%f %f",&a[i][0],&a[i][1]);
    }
    printf("Enter total weight:\n");
    scanf("%f",&w);
    printf("Profit by Weights:  ");
    for (i=0; i<n; i++)
    {
        a[i][2]=a[i][0]/a[i][1];
        printf("%f\t",a[i][2]);
    }

    float p=knapsack(a,n,w);
    printf("\nProfit: %.2f",p);
}