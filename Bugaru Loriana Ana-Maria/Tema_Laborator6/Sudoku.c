#include <stdio.h>
#include <stdlib.h>

#define SIZE 9


int sudoku[9][9] =
{
	{6,5,0,8,7,3,0,9,0},
	{0,0,3,2,5,0,0,0,8},
	{9,8,0,1,0,4,3,5,7},
	{1,0,5,0,0,0,0,0,0},
	{4,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,5,0,3},
	{5,7,8,3,0,1,0,2,6},
	{2,0,0,0,4,8,9,0,0},
	{0,9,0,6,2,5,0,8,1}
};


void Afisare()
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%d\t", sudoku[i][j]);
		}
		printf("\n\n");
	}
}


int Numar_nerepartizat(int *rand, int *coloana)
{
	int nr_nerepartizat = 0;
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			
			if (sudoku[i][j] == 0)
			{
				
				*rand = i;
				*coloana = j;
				
				nr_nerepartizat = 1;
				return nr_nerepartizat;
			}
		}
	}
	return nr_nerepartizat;
}


int Verificare_numar(int numar, int rand, int coloana)
{
	int i, j;
	
	for (i = 0; i < SIZE; i++)
	{
		if (sudoku[rand][i] == numar)
			return 0;
	}

	for (i = 0; i < SIZE; i++)
	{
		if (sudoku[i][coloana] == numar)
			return 0;
	}

	int rand_mic = (rand / 3) * 3;
	int coloana_mica = (coloana / 3) * 3;
	for (i = rand_mic; i < rand_mic + 3; i++)
	{
		for (j = coloana_mica; j < coloana_mica + 3; j++)
		{
			if (sudoku[i][j] == numar)
				return 0;
		}
	}
	return 1;
}


int Rezolvare_sudoku()
{
	int rand;
	int coloana;
	
	if (Numar_nerepartizat(&rand, &coloana) == 0)
		return 1;
	int numar, i;
	
	for (i = 1; i <= SIZE; i++)
	{
	
		if (Verificare_numar(i, rand, coloana))
		{
			sudoku[rand][coloana] = i;
			
			if (Rezolvare_sudoku())
				return 1;
			
			sudoku[rand][coloana] = 0;
		}
	}
	return 0;
}

int main()
{
	if (Rezolvare_sudoku())
		Afisare();
	else
		printf("Imi pare rau, nu merge frate! \n");
	return 0;
}