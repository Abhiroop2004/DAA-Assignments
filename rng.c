#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    FILE *r=fopen("random.txt","w");
    printf("Enter length of array:  ");
    scanf("%d",&n);
    int i,a[n];
    for (i=0; i<n; i++)
    {
        a[i]=rand()%1000;
        fprintf(r,"%d\n",a[i]);
    }
    fclose(r);
    printf("Completed!");
}
