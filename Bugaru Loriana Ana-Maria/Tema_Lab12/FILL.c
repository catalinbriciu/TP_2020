#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int matrice_fill[MAX][MAX], n, m, i, j, P_i, P_j;

void fill(int i, int j)
{
	if (matrice_fill[i][j] == 0)
	{
		matrice_fill[i][j] = 1;
		fill(i - 1, j);
		fill(i, j + 1);
		fill(i + 1, j);
		fill(i, j - 1);
	}
}

int main()
{
	printf("Numarul de randuri= ");
	scanf("%d", &n);
	printf("Numarul de coloane= ");
	scanf("%d", &m);
	printf("Matrice: \n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			printf("matrice_fill[%d][%d]=", i, j);
			scanf("%d", &matrice_fill[i][j]);
		}
	
	printf("Rand P=");
	scanf("%d", &P_i);
	printf("Coloana P=");
	scanf("%d", &P_j);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (P_j == j && P_i == i)
				fill(i, j);
	printf("Matrice noua: \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			printf("%d ", matrice_fill[i][j]);
		printf("\n");
	}
	return 0;
}