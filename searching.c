#include <stdio.h>
#include <stdlib.h>
int binarysearch(int a[], int lb, int ub, int s, int* steps)
{
    if (ub > lb)
    {
        (*steps)++;
        int mid = (lb + ub) / 2;
        if (a[mid] == s)
            return mid;
        else if (a[mid] < s)
            return binarysearch(a, mid + 1, ub, s, steps);
        else
            return binarysearch(a, lb, mid - 1, s, steps);
    }
    return -1;
}

int linearsearch(int a[], int n, int s, int *steps)
{
	int i;
	for (i=0;i<=n;i++)
	{
		(*steps)++;
		if (a[i]==s)
			return i;
	}
	return -1;
}

int main()
{
    int steps = 0, n = 100, i, val, c, r=-1;
    FILE *file;
    file = fopen("randoms.txt", "r");
    char temp[6];
    int a[n];
    printf("Enter which type of search you want to do\n");
    printf("1 for Linear Search, 2 for Binary Search: ");
    scanf("%d",&c);
    printf("Enter element to search:");
    scanf("%d",&val);
    for (i=0;i<n;i++)
    {
        fgets(temp, sizeof(temp), file);
        a[i]=atoi(temp);
    }
    fclose(file);
    if (c==1)
        r= linearsearch(a, n, val, &steps);
    else if (c==2)
        r = binarysearch(a, 0, n , val, &steps);
    else
        printf("Wrong Choice!");
    printf("The elements of the array are - ");
    for (i = 0; i < 100; i++)
        printf("%d\n", a[i]);
    printf("\nElement to be searched is - %d", val);
    printf("\nSteps Reqired: %d", steps);
    if (r == -1)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present at position: %d ", r);
    return 0;
}