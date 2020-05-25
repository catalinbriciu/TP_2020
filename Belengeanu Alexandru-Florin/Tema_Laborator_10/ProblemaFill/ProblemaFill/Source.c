#include <stdio.h>
#include <stdlib.h>
int a[100][100];
void FILL(int i, int j) { // FILL/umplere recursiva
	if (!a[i][j]) {
		a[i][j] = 1; //umple
		FILL(i - 1, j); //sus
		FILL(i, j + 1); //dreapta
		FILL(i + 1, j); //jos
		FILL(i, j - 1); //stanga
	}
}
int main()
{
	for (int i = 0;i < 7;i++)
		for (int j = 0;j < 6;j++)
			scanf("%d", &a[i][j]);
	printf("\nMatricea inainte de aplicarea algoritmului FILL : \n");
	for (int i = 0;i < 7;i++) {
		printf("\n");
		for (int j = 0;j < 6;j++) {
			printf("%d  ", a[i][j]);
		}
	}
	FILL(2, 3);
	printf("\nMatricea dupa aplicarea algoritmului FILL : \n");
	for (int i = 0;i < 7;i++) {
		printf("\n");
		for (int j = 0;j < 6;j++) {
			printf("%d  ", a[i][j]);
		}
	}
	system("pause");
	return 0;
}