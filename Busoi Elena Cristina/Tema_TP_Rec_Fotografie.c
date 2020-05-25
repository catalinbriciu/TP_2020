#include <stdio.h>
#include <stdlib.h>
int a[100][100], n, m;
int dx[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int dy[] = {  0,  1, 1, 1, 0, -1, -1, -1 };

void Read_matrix() {
	FILE *f;
	int i, j;
	f = fopen("in.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fscanf(f, "%d", &a[i][j]);
	fclose(f);
}
void Print() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
int Valid(int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	if (i >= n || j >= m)
		return 0;
	if (a[i][j] != 1)
		return 0;
	return 1;
}
void FILL(int i, int j, int c) { // FILL/umplere recursiva
	int k;
	if (Valid(i, j)) {
		a[i][j] = c; //umple
		for (k = 0; k < 8; k++)
			FILL(i + dx[k], j + dy[k], c);
	}
}

int main() {
	int c, i, j;
	Read_matrix();
	c = 1;
	for(i = 0; i < n;i++)
		for(j = 0; j < m;j++)
			if(a[i][j] == 1)			
		FILL(i, j, ++c);
	Print();
	system("pause");
	return 0;
}