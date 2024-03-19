#include <stdio.h>
#include <string.h>

void lcs(char s1[], char s2[], int m, int n) 
{
    int table[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
        table[i][0] = 0;
    for (j = 0; j <= n; j++)
        table[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) 
        {
            if (s1[i - 1] == s2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = (table[i][j - 1] > table[i - 1][j]) ? table[i][j - 1] : table[i - 1][j];
        }
    }
    int l = table[m][n];
    char longest[l + 1];
    longest[l] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0) 
    {
        if (s1[i - 1] == s2[j - 1]) 
        {
            longest[--l] = s1[i - 1];
            i--;
            j--;
        } 
        else if (table[i - 1][j] > table[i][j - 1]) 
            i--;
      	 else 
            j--;
    }
    printf("Length: %d\n", table[m][n]);
    printf("Longest Common subsequence: %s\n", longest);
}

int main() 
{
    char s1[] = "aghfde";
    char s2[] = "dagf";
    lcs(s1, s2, strlen(s1), strlen(s2));
    return 0;
}
