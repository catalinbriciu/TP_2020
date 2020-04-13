#include <stdio.h>

//Numar de regine
int N;

//initializam tabla de sah
int tabla[100][100];

//functie de a verifica daca celula este atacata sau nu
int atac(int i, int j)
{
	int k, l;
	//verificam daca este o regina pe coloana sau linie
	for (k = 0; k < N; k++)
	{
		if ((tabla[i][k] == 1) || (tabla[k][j] == 1))
			return 1;
	}
	//Verificam si pentru diagonale
	for (k = 0; k < N; k++)
	{
		for (l = 0; l < N; l++)
		{
			if (((k + l) == (i + j)) || ((k - l) == (i - j)))
			{
				if (tabla[k][l] == 1)
					return 1;
			}
		}
	}
	return 0;
}

int N_regina(int n)
{
	int i, j;
	//functia solution
	if (n == 0)
		return 1;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			//Verificam daca putem pune o regina 
			//Regina nu va putea fi pozitionata daca locul este atacat sau ocupat deja
			if ((!atac(i, j)) && (tabla[i][j] != 1))
			{
				tabla[i][j] = 1;
				//Apelam functia recursiv 
				//Verificam daca putem pune urmatoarea regina
				if (N_regina(n - 1) == 1)
				{
					return 1;
				}
				tabla[i][j] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	printf("Introdu numarul de regine si tabla de NxN: \n");
	scanf("%d", &N);

	int i, j;
	//Setam initial ca toate elementele matricei la elementul 0
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			tabla[i][j] = 0;
		}
	}
	//"Sunam" functia :))
	N_regina(N);
	//In final printam functia 
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d\t", tabla[i][j]);
		printf("\n");
	}

}