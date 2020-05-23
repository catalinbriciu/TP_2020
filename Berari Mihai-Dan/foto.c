#include <stdio.h>
#include <stdlib.h>
#define DIM 8
int a[DIM][DIM]={{0, 0, 0, 1, 1, 0, 1, 0},
                 {1, 1, 0, 0, 0, 1, 0, 0},
                 {1, 1, 0, 1, 0, 1, 0, 0},
                 {1, 1, 0, 0, 0, 0, 0, 0},
                 {1, 1, 0, 0, 0, 0, 0, 0},
                 {1, 0, 0, 1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0, 0, 1}};
int x[8] = {-1,-1,-1,0,1,1,1,0};
int y[8] = {-1,0,1,1,1,0,-1,-1};
int nrObj = 1;


void FillObj(int i, int j)//marcare recursiva 
{ 
	int k; //local !

	if (a[i][j] == 1)
	{
		a[i][j] = nrObj; //numarul curent al obiectului
		for (k=0;k<8;k++) //cele 8 directii
			FillObj(i+x[k],j+y[k]);
	}	
}



int main()
{
	int i, j;
	for (i = 0; i < DIM; i++)
		for (j = 0; j < DIM; j++)
			if (a[i][j] == 1)
			{
				nrObj++;
				FillObj(i, j);
			}
	printf("FOTOGRAFIILE MATRICEI SUNT:\n");
	for (i = 0; i < DIM; i++) {
		//if (i == 2 || i == 5) printf("---------------------\n");
		for (j = 0; j < DIM; j++) {
			//if (j == 2 || j == 4) printf("||");
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
