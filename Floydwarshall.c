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
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (distance[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", distance[i][j]);
            }
        }
        printf("\n");
    }
}

int main() 
{
    int a[3][3] = {{0, 4, 2}, {INT_MAX, 0, 5}, {2, 1, 0}};
    floyd(3, a);
}
