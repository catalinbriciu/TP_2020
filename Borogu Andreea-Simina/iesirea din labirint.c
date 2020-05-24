#include <stdio.h>
#include <stdlib.h>

int fill(int tab[8][8], int x, int y, int pas)
{

	if (x < 0 || x >= 8 || y < 0 || y >= 8)
		return 0;
	else

		if (tab[x][y] == 1)
		{
			tab[x][y] = pas;

			fill(tab, x + 1, y, pas + 1);
			fill(tab, x - 1, y, pas + 1);
			fill(tab, x, y + 1, pas + 1);
			fill(tab, x, y - 1, pas + 1);
		}

}

int main()
{
	int n, a[8][8], i, j, pozInitRand, pozInitCol, pozFinRand, pozFinCol, gasit = 0;
	FILE* f;
	f = fopen("Fisier.txt", "a+t");
	if (f == NULL)
		printf("Error!\n");
	else
	{
		while (!feof(f))
		{
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					fscanf(f, "%d", &a[i][j]);
		}
	}
	fclose(f);
	printf("Matricea initiala: (0 - perete; 1- culoar)\n");
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("Matricea finala: (0 - perete; 1 culoar;  ruta pozitie initiala -> pozitie finala: in ordine crescatoare incepand de la 2)\n");
	gasit = 0;
	while (gasit != 1)
	{
		pozInitRand = rand() % 8;
		pozInitCol = rand() % 8;
		if (a[pozInitRand][pozInitCol] == 1)
		{
			gasit = 1;
		}

	}
	gasit = 0;
	while (gasit != 1)
	{
		pozFinRand = rand() % 8;
		pozFinCol = rand() % 8;
		if (a[pozFinRand][pozFinCol] == 1)
		{
			gasit = 1;
		}

	}
	printf("Pozitia initiala: (%d, %d)\n", pozInitCol, pozInitCol);
	printf("Pozitia finala: (%d, %d)\n", pozFinRand, pozFinCol);
	a[pozInitRand][pozInitCol] = 1;
	fill(a, pozInitRand, pozInitCol, 2);
	if (a[pozFinRand][pozFinCol] == 1)
		printf("Nu exista solutie");
	else
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}


	system("pause");
	return 0;
}