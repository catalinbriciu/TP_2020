#include<stdio.h>
#include<conio.h>
int a[8][8] = {
{ 0, 0, 0, 1, 1, 0, 1, 0 },
{ 1, 1, 0, 0, 0, 1, 0, 0 },
{ 1, 1, 0, 1, 0, 1, 0, 0 },
{ 1, 1, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 1, 0, 0, 0, 1 },
{ 1, 1, 1, 1, 0, 0, 1, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 1 } };
int i, m = 8, n = 8, j, nrObj;
int x[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int y[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
void FillObj(int i, int j) {
	int k; 
	if (a[i][j] == 1){
		a[i][j] = nrObj; //numarul curent al obiectului
		for (k = 0; k < 8; k++) //cele 8 directii
			if (i + x[k] >= 0 && i + x[k] < n && j + y[k] >= 0 && j + y[k] < m)
				FillObj(i + x[k], j + y[k]);
	}
}
int main(){
	for (i = 0; i < 8; i++){
		printf("\n");
		for (j = 0; j < 8; j++)
			printf("%d ", a[i][j]);
	}
	printf("\n");
	nrObj = 2;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (a[i][j] == 1){
				FillObj(i, j);
				nrObj++;
			}
	for (i = 0; i < 8; i++){
		printf("\n");
		for (j = 0; j < 8; j++)
			printf("%d ", a[i][j]);
	}

}