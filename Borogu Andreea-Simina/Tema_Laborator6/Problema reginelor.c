#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
int ataca(int linie, int memorie[])
//aceasta funcþie testeazã daca regina de pe linie este atacata de reginele poziþionate anterior.Este de fapt funcþia de Validare//
{
	int i;
	//luam pe rând toate damele poziþionate anterior//
	for (i = 0; i < linie; i++)
		//verificam daca cele 2 dame sunt pe aceeaºi coloana sau pe diagonalã//
		if ((memorie[linie] == memorie[i]) ||
			(abs(memorie[i] - memorie[linie]) == linie - i))
			// se ataca, deci nu sunt corect poziþionate.//
			return 1;
		else
	       return 0; //daca am ajuns aici, înseamnã cã nu se atacã//
}
//cãile de afiºare sunt infinite//
void afiseaza(int dim, int memorie[])
{
	int l, c;
	for (l = 0; l <= dim; l++)
		printf("_");
	for (l = 0; l < dim; l++)
	{
		printf("\n|");
		for (c = 0; c < dim; c++)
			if (memorie[l] == c)
				printf("%c", 6);
			else
				if ((l + c) & 1)
					printf(" ");
				else
					printf("%c", 219);
		printf("|");
	}
	printf("\n");
	for (l = 0; l <= dim; l++)
		printf("-");
	printf("\n");
	printf("o tasta!\n");
	getch();
}
void regine(int dim, int linie, int memorie[])
// aici este funcþia care face efectiv backtracking-ul (suntem la linia(nivelul) linie.//
// dim ne spune cât de mare-i tabla//
// memorie tine minte damele deja poziþionate. Ea este stiva.//
{
	if (linie == dim)// daca am terminat//
		afiseaza(dim, memorie);//afiºãm//
	else //altfel avem de lucru//
		for (memorie[linie] = 0; memorie[linie] < dim; memorie[linie]++)
			//încercam toate coloanele de la stânga la dreapta//
			if (!ataca(linie, memorie))
				//daca e o poziþie valida trecem la nivelul urmãtor//
				regine(dim, linie + 1, memorie);
	//când ne întoarcem din apelul recursiv înseamnã cã am revenit la acest nivel ºi încercãm urmãtoarea coloana//
}

void main()
{
	int n, memorie[100];
	printf("dimensiunea tablei de joc");
	scanf("%d", &n);
	regine(n, 0, memorie);// prima linie are numãrul zero//
}