#include <stdio.h>
void heapify (int a[],int n, int i, int* steps)
{
    int max, left, right;
    max=i;
    left=2*i+1;
    right=2*i+2;
    if (left<n && a[left]>a[max]) max=left; (*steps)++;
    if (right<n && a[right]>a[max]) max=right;  (*steps)++;
    if (max==i) return;
    int temp=a[i];
    a[i]=a[max];
    a[max]=temp;
    (*steps)++;
    heapify(a,n,max, steps);
}
void heapsort (int a[], int n, int* steps)
{
    int i;
    for (i=n/2-1;i>=0;i--)
        heapify(a,n,i, steps);
    for (i=n-1;i>=0;i--)
    {
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp; 
        (*steps)++;
        heapify(a,i,0, steps);
    }
}

void merge(int a[], int begin, int mid, int end, int* steps)
{
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int la[n1], ra[n2];
    for (i = 0; i < n1; i++) 
    {
        (*steps)++;
        la[i] = a[begin + i];
    }
    for (j = 0; j < n2; j++) 
    {
        (*steps)++;
        ra[j] = a[mid + 1 + j];
    }
    i = j = 0;
    k = begin;
    while (i < n1 && j < n2)
    {
        if (la[i] <= ra[j])
            a[k++] = la[i++];
        else
        {
            a[k++] = ra[j++];
            (*steps)++;
        }
    }
    while (i < n1)
    {
        a[k++] = la[i++]; 
        (*steps)++;
    }
    while (j < n2)
    {
        a[k++] = ra[j++]; 
        (*steps)++;
    }
}

void mergeSort(int a[], int begin, int end, int *steps)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(a, begin, mid, steps);
        mergeSort(a, mid + 1, end, steps);
        merge(a, begin, mid, end, steps); // Count steps during merge operation
    }
}


int partition(int a[], int begin, int end, int *steps) 
{
    int pivot = a[end];
    int i, j = begin;
    for (i = begin; i < end; i++) 
    {
        (*steps)++;
        if (a[i] < pivot) {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            j++;
        }
    }
    (*steps)++;
    int t = a[j];
    a[j] = a[end];
    a[end] = t;
    return j;
}

int quickSort(int a[], int start, int end, int *steps) 
{
    if (start < end) 
    {
        int p = partition(a, start, end - 1, steps);
        quickSort(a, start, p, steps);
        quickSort(a, p + 1, end, steps);
    }
}

//Print for testing only
void printarray (int a[], int n)
{
    int i;
    for (i=0;i<n;i++)
    printf("%d \n",a[i]);
}

int main() 
{
    int steps = 0, n = 1000, i, c;
    FILE *file;
    file = fopen("random.txt", "r");
    char temp[6];
    int a[n];
    fgets(temp, sizeof(temp), file);
    for (i = 0; i < n; i++) 
    {
        fgets(temp, sizeof(temp), file);
        a[i] = atoi(temp);
    }
    fclose(file);
    printf("Enter which type of sorting you want to do\n");
    printf("1 for Merge Sort, 2 for Quick Sort, 3 for Heap Sort: ");
    scanf("%d", &c);
    if (c == 1)
    {
        mergeSort(a, 0, n - 1, &steps); 
        printarray(a,n);
    }
    else if (c == 2)
    {
        quickSort(a, 0, n, &steps); 
        printarray(a,n);
    }
    else if (c == 3)
    {
        heapsort(a, n, &steps); 
        printarray(a,n);
    }
    else
        printf("Wrong Choice!");
    printf("steps= %d", steps);
    return 0;
}
