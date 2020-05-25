#include<stdio.h> 
#include<conio.h>
#define max 20 
#pragma warning (disable:4996)
int Matrix[7][6] = {
{ 0, 0, 1, 1, 1, 1 }, 
{ 1, 1, 0, 0, 0, 1 },
{ 1, 1, 0, 0, 0, 1 },
{ 1, 1, 0, 0, 1, 1 }, 
{ 1, 1, 1, 1, 0, 0 }, 
{ 1, 0, 0, 1, 0, 0 },
{ 1, 1, 1, 1, 0, 0 } };

void fill(int x, int y){
	if ((x > 0) && (x < 7))
		if ((y > 0) && (y < 6))
			if (Matrix[x][y] == 0)
			{
				Matrix[x][y] = 1;
				fill(x - 1, y);
				fill(x + 1, y);
				fill(x, y - 1);
				fill(x, y + 1);
			}
}
void afisare(int Matrix[7][6]){
	int i, j;
	for (i = 0; i < 7; i++){
		printf("\n");
		for (j = 0; j < 6; j++)
			printf("%d ", Matrix[i][j]);
	}
}

int main(){
	int x, y;
	printf("Introduceti coordonata x: ");
	scanf("%d", &x); printf("Introduceti coordonata y: ");
	scanf("%d", &y);
	fill(x, y);
	printf("Matricea noua dupa aplicarea tehnicii fill la coord M[%d][%d] este: \n", x, y);
	afisare(Matrix);
	return 0;
	system("pause");
}
