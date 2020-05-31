#include <stdio.h> 
#define BANCNOTE 7
#define MAX 200 
 
int bani[BANCNOTE] = { 1, 5, 10, 50, 100, 200, 500};

void Numar_min_bani(int suma)
{
	int lista_bani[MAX] = { 0 };
	int i, k = 0;

	for (i = BANCNOTE-1 ; i >= 0; i--) 
	{
		while (suma >= bani[i])
		{
			suma = suma - bani[i];

			lista_bani[k++] = bani[i];
		}
	}

	for (i = 0; i < k; i++)
	{ 
		printf("%d ", lista_bani[i]);
	}
	return 0;
}

int main()
{ 
	int suma;
	printf("Introduceti suma: ");
	scanf("%d", &suma);
    printf("Pentru suma de %d se va folosi numarul minim de bancnote: ",suma);
	Numar_min_bani(suma);
	printf("\n");
	return 0;
}