#include <stdio.h>
#include <conio.h>
#pragma warning (disable:4996)
int x[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int i, j, lin, col, x_start, y_start, Maze[10][10];
FILE* f;
void print(int i, int j) {
	int k;
	if (Maze[i][j] != 2) {
		for (k = 0; k < 8; k++)
			if (Maze[i + x[k]][j + y[k]] == Maze[i][j] - 1) {
				print(i + x[k], j + y[k]);
				printf("(%d,%d) -> ", i, j);
				break;
			}
	}
	else
		printf("(%d,%d) -> ", i, j);
}

void search(int i, int j) {
	int k;
	if (i == 0 || i == lin - 1 || j == col - 1 || j == 0) {
		printf("(%d,%d)", x_start, y_start);
		print(i, j);
		printf("\n");
	}
	else
		for (k = 0; k < 8; k++) {     // se cauta trasee in 8 directii Vertical,Orizontal si pe Diagonale
			if (Maze[i + x[k]][j + y[k]] == 0) {
				Maze[i + x[k]][j + y[k]] = Maze[i][j] + 1;
				search(i + x[k], j + y[k]);
				Maze[i + x[k]][j + y[k]] = 0;
			}
		}
}
int main() {
	int i, j;
	f = fopen("in.txt", "rt");  //citire matrice din fisier
	if (f == NULL)
		return 0;
	else
		while (!feof(f)){
			fscanf(f, "%d%d", &lin, &col); //citire nr linii,coloane
			fscanf(f, "%d%d", &x_start, &y_start); // citire punct de plecare din labirint
			for (i = 0; i < lin; i++)
				for (j = 0; j < col; j++)
					fscanf(f, "%d", &Maze[i][j]);  //citire matricea labirint 1=zid 0=camera libera 		                                       
		}
	fclose(f);

	Maze[x_start][y_start] = 5;   //initializez punctul de plecare cu o cifra sa il disting de obstacole(1) si de traseu(2)
	printf("\n");
	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++)
			printf("%d ", Maze[i][j]);
		printf("\n");
	}
	printf("\n\n");
	search(x_start, y_start);
	return 0;
	system("pause");
}