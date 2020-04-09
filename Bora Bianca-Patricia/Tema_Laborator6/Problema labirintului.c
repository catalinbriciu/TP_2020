#include<stdio.h>
#include<conio.h>
//Matricea a contine valorile labirintului,iar in matricea rez vom pastra drumul parcurs in cadrul unei posibile solutii
int a[10][10], rez[10][10], n;
void scrie(void) {
	int i, j;
	for (i = 0; i < n; i++) {
		//afisam matricea drumului de iesire; succesiunea de 1 reprezinta drumul
		for (j = 0; j < n; j++)
			printf("%d", rez[i][j]);
		putchar("\n");
	}
	putchar("\n");
	//dupa fiecare solutie se asteapta apasarea unei taste 
	getch();
}
void labirint(int x, int y) {
	//daca am atins una din marginile matricei
	if ((x == 0) || (x == n - 1) || (y = 0) || (y == n - 1)) {// marcam punctul de margine ca vizitat
		rez[x][y] = 1;
		//apelam functia de afisare
		scrie();
	}
	else
		//in cazul in care nu suntem pe margine
	{
		//inceram directia 1 din figura de mai sus;rez trebuie sa contina valoarea 0(in cadrul drumului curent sa nu fi sarit in acest nou punct iar in matricea labirint sa avem drum(adica val 1)
		if ((x + 1 < n) && (rez[x + 1][y] == 0) && (a[x + 1][y] == 1)) {
			//marcam vizitat punctul in care am sarit 
			rez[x + 1][y] = 1;
			//apelam functia minge porning de la acest nou punct
			labirint(x + 1, y);
			//la revenire din backtracking punem din nou valoarea 0 in matricea drumului
			rez[x+1][y] = 0;
		}
		//incercam directia 2
		if ((y - 1 >= 0) && (rez[x][y - 1] == 0) && (a[x][y - 1] == 1)) {
			rez[x][y - 1] == 1;
			labirint(x , y-1);
			rez[x][y - 1] == 0;

		}
		//incercam directia 3
		if ((x - 1 >= 0) && (rez[x - 1][y] == 0) && (a[x - 1][y] == 1)) {
			rez[x - 1][y] == 1;
			labirint(x - 1, y);
			rez[x - 1][y] == 0;
		}
		//incercam directia 4
		if ((y + 1 < n) && (rez[x][y + 1] == 0) && (a[x][y + 1] == 1)) {
			rez[x][y + 1] == 1;
			labirint(x, y + 1);
			rez[x][y + 1] == 0;
		}
	}
}
void main(void) {
	int i, j, xi, yi;
	printf("Introduceti dimensiunea matricii");
	scanf("%d", &n);
	printf("Introduceti valorile matricii labirint");
	for (i = 0; i < n; i++)
		for (j = 0; j <= n; j++)
		{
			printf("a[% d][% d] =", i, j); //se citeste 1 pentru drum si 0 pentru zid
			scanf("%d", &a[i][j]); //initializam matricea drumului
			rez[i][j] = 0;
		}
	printf("Introduceti linia de pornire ");
	scanf("%d", &xi);
	printf("Introduceti coloana de pornire ");
	scanf("%d", &yi);
	//drumul incepe din punctul initial
	rez[xi][yi] == 1;
	labirint(xi, yi);

}


