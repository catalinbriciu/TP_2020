#include <stdio.h>
#include <stdlib.h>
int n, m, a[100][100];
int dx[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dy[] = {  0,  1, 1, 1, 0, -1, -1, -1 };
int startX, startY;

void Read_matrix() {
	FILE *f;
	int i, j;
	f = fopen("in.txt", "r");
	fscanf(f, "%d%d%d%d", &n, &m, &startX, &startY);
	for(i = 0; i < n;i++)
		for(j = 0;j < m;j++)
			fscanf(f, "%d", &a[i][j]);
	fclose(f);
}
void Print(){
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			if (i == startX && j == startY)
				  printf("P ");
		else 
				printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("--------------------------------------------\n\n");
}
void Search(int i, int j) {
	int k;
	if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
	Print();	
	}
	else
		for (k = 0; k < 8; k++) {
			if (a[i + dx[k]][j + dy[k]] == 0) {
				a[i + dx[k]][j + dy[k]] = a[i][j] + 1;
				Search(i + dx[k], j + dy[k]);
				a[i + dx[k]][j + dy[k]] = 0; 
			}
		}
}

int main() {
	Read_matrix();
	startX--;
	startY--;
	Search(startX, startY);
	return 0;
}