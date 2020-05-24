#include <stdio.h>
#include <stdlib.h>
int a[100][100];
int nrObj = 0;
int x[8] = { -1,-1,-1,0,1,1,1,0 };
int y[8] = { -1,0,1,1,1,0,-1,-1 };
void FillObj(int i, int j) { 
	int k; 
	if (a[i][j] == 1) {
		a[i][j] = nrObj; 
		for (k = 0;k < 8;k++) 
			FillObj(i + x[k], j + y[k]);
	}
}
int main()
{
	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++)
			scanf("%d", &a[i][j]);
	printf("\nMatricea inainte de aplicarea algoritmului fotografiei : \n");
	for (int i = 0;i < 8;i++) {
		printf("\n");
		for (int j = 0;j < 8;j++) {
			printf("%d  ", a[i][j]);
		}
	}
	for (int i = 0;i < 8;i++) {
		nrObj++;
		for (int j = 0;j < 8;j++) {
			FillObj(i, j);
		}
	}

	printf("\nMatricea dupa aplicarea algoritmului fotografiei : \n");
	for (int i = 0;i < 8;i++) {
		printf("\n");
		for (int j = 0;j < 8;j++) {
			printf("%d  ", a[i][j]);
		}
	}

	system("pause");
	return 0;
}