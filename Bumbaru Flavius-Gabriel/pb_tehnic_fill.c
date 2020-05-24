#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int v[MAX][MAX], n, m, i, j, pi, pj;

void fill(int i, int j)
{
    if (v[i][j] == 0)
    {
        v[i][j] = 1;
        fill(i - 1, j);
        fill(i, j + 1);
        fill(i + 1, j);
        fill(i, j - 1);
    }
}

int main()
{
    printf("n=");
    scanf("%d", &n);
    printf("m=");
    scanf("%d", &m);
    printf("Matrice: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            printf("v[%d][%d]=",i,j);
            scanf("%d", &v[i][j]);
        }
    printf("Coordonate P \ni=");
    scanf("%d", &pi);
    printf("j=");
    scanf("%d", &pj);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (pj == j && pi == i)
                fill(i, j);
    printf("Matrice noua: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    return 0;
}
