#include<stdio.h>
#include<conio.h>
#define col 6
#define line 7
int i, j, pi, pj;
int a[line][col]={{0, 0, 1, 1, 1, 1},
                  {1, 1, 0, 0, 0, 1},
                  {1, 1, 0, 0, 0, 1},
                  {1, 1, 0, 0, 1, 1},
                  {1, 1, 1, 1, 0, 0},
                  {1, 0, 0, 1, 0, 0},
                  {1, 1, 1, 1, 0, 0}};

void fill(int i, int j)
{
	if (a[i][j]==0)
	{
		a[i][j] = 1;
		fill(i - 1, j);
		fill(i, j + 1);
		fill(i + 1, j);
		fill(i, j - 1);
	}
}
int main()
{
	//int i, j;
	printf("Coordonate P \ni=");
		scanf("%d", &pi);
		printf("j=");
		scanf("%d", &pj);
		for (i = 0; i < line; i++) 
		{
			for (j = 0; j < col; j++)
			{
				if (pi == i && pj == j) 
				{
					printf("a[%d][%d]=%d\n", pi, pj, a[i][j]);
					fill(i, j);
				}
					
			}
		}
		printf("Matricea colorata este:\n");
		for (i = 0; i < line; i++) 
		{
			//if (i == 2 || i == 5) printf("---------------------\n");
			for (j = 0; j < col; j++) 
			{
				//if (j == 2 || j == 4) printf("||");
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	system("pause");
	return 0;
}
//