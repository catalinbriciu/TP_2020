#include <stdio.h>
#include <stdlib.h>

int a[100][100];

void fill(int i, int j)
{
	if (!a[i][j])
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
	int l,c,i,j,x,y;
	printf("Introduceti nr de linii si de coloane:"); scanf("%d %d", &l, &c);
	printf("Introduceti matrice:");
	for (x = 0;x < l;x++)
	{
		for (y = 0;y < c;y++)
		{
			
			scanf("%d", &a[x][y]);
		}
		
	}
	printf("Introduceti punctul:"); scanf("%d %d", &i, &j);
	fill(i, j);
	for (x = 0;x < l;x++)
	{
		for (y = 0;y < c;y++)
		{
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}