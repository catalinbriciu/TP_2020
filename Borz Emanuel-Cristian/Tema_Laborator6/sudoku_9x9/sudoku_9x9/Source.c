#include<stdlib.h>
#include <stdio.h>
//#include<stdbool.h>
#define DIMENSIUNE 9
#pragma warning (disable:4996)
#pragma warning (disable:4005)
int matrice[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0} };

void afiseaza_sudoku() {
	int i, j;
	for (i = 0; i < DIMENSIUNE; i++) {
		if (i == 3 || i == 6) printf("\n ----------------------------------------------------------------------- \n");
		for (j = 0; j < DIMENSIUNE; j++) {
			if (j == 3 || j == 6) printf("||");
			printf("  %d  \t", matrice[i][j]);
		
		}
		printf("\n\n");
	}
}

int camp_necompletat(int* linie, int* col) {
	int necompletat = 0;
	int i, j;
	for (i = 0; i < DIMENSIUNE; i++) {
		for (j = 0; j < DIMENSIUNE; j++) {
			if (matrice[i][j] == 0) {
				*linie = i;
				*col = j;
				necompletat = 1;
				return necompletat;
			}
		}
	}
	return necompletat;
}

int isValid(int n, int r, int c) {// r= rand c=col
	int i, j;
	for (i = 0; i < DIMENSIUNE; i++) {

		if (matrice[r][i] == n)
			return 0;
	}
	for (i = 0; i < DIMENSIUNE; i++) {

		if (matrice[i][c] == n)
			return 0;
	}
	int rand_inceput = (r / 3) * 3;
	int col_inceput = (c / 3) * 3;
	for (i = rand_inceput; i < rand_inceput + 3; i++) {
		for (j = col_inceput; j < col_inceput + 3; j++) {
			if (matrice[i][j] == n)
				return 0;
		}
	}
	return 1;
}

int Rezolva() {
	int n,i,linie, col;
	if (camp_necompletat(&linie, &col) == 0)
		return 1;

	for (i = 1; i <= DIMENSIUNE; i++) {
		if (isValid(i, linie, col))
		{
			matrice[linie][col] = i;

			if (Rezolva())
				return 1;
			matrice[linie][col] = 0;
		}
	}
	return 0;
}
int main()
{
	if (Rezolva())
		afiseaza_sudoku();
	else
		printf("Nu se poate rezolva / Date initiale invalide \n");
	return 0;
	system("pause");
}