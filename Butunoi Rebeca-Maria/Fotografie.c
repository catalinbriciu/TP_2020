#include<stdio.h>
#include<stdlib.h>

int A[20][20], n, m, obj = 1;
int x[8] = { -1,-1,-1,0,1,1,1,0 };
int y[8] = { -1,0,1,1,1,0,-1,-1 };

void FillOBJ(int i, int j)
{
	int k;
	if (A[i][j] == 1)
	{
		A[i][j] = obj;
		for (k = 0; k < 8; k++)
			FillOBJ(i + x[k], j + y[k]);
	}
}

int main()
{
	int i, j;
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
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			if (A[i][j] == 1)
			{
				obj++;
				FillOBJ(i, j);
			}
		}

	printf("Sunt %d obiecte", obj - 1);

	system("pause");
	return 0;
}