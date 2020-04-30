#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 9
int matrix[9][9] = {  {3, 0, 6, 5, 0, 8, 4, 9, 0},
					  {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0} };
int spatiu_gol(int *line, int *column){
	int i, j;
	int gol = 0;

	for (int i = 0; i < DIM; i++)	{
		for (int j = 0; j < DIM; j++)
			if (matrix[i][j] == 0)			{
				*line = i;
				*column = j;
				gol = 1;
				return gol;
			}
	}
	return gol;
}
int IsValid(int n, int line, int col){
	int i, j;
	int lineprim = (line / 3) * 3;
	int columnprim = (col / 3) * 3;
	for (int i = 0; i < DIM; i++){
		if (matrix[line][i] == n){
			return 0;
		}
	}
	for (int i = 0; i < DIM; i++){
		if (matrix[i][col] == n){
			return 0;
		}
	}

	for (i = lineprim; i < lineprim + 3; i++){
		for (j = columnprim; j < columnprim + 3; j++){
			if (matrix[i][j] == n)
				return 0;
		}
	}

}
void PrintMX()
{
	int i, j;
	for (i = 0; i < DIM; i++) {
		if (i == 3 || i == 6) printf("---------------------\n");
		for (j = 0; j < DIM; j++){
			if (j == 3 || j == 6) printf("||");
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
int Back()
{
	int i, n, column, line;
	if (spatiu_gol(&line, &column) == 0)
		return 1;
	for (i = 1; i <= DIM; i++)
	{
		if (IsValid(i, line, column))
		{
			matrix[line][column] = i;
			if (Back())
				return 1;
			matrix[line][column] = 0;
		}
	}
	return 0;
}
int main()
{
	if (Back())
		PrintMX();
	else
		printf("DO IT YOURSELF");
	getch();
	system("pause");
	return 0;
}