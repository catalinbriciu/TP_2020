#include<stdio.h>
#include<stdlib.h>

int A[20][20], n, m;



void Fill(int x, int y)
{
	if (A[x][y] < 1)
	{
		A[x][y] = 3;
		Fill(x - 1, y);
		Fill(x, y + 1);
		Fill(x + 1, y);
		Fill(x, y - 1);
	}
}

int main()
{
	int i, j, x, y, m, n;
	printf("Introduceti numarul de linii: "); scanf("%d", &n);
	printf("Introduceti numarul de coloane: "); scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("Introduceti 1 sau 0 :");
			scanf("%d", &A[i][j]);
		}
	}

	printf("Introduceti coordonatele punctul: x= ");
	scanf("%d", &x);
	printf("y= ");
	scanf("%d", &y);

	Fill(x, y);
}