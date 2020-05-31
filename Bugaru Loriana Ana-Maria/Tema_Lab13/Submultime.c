#include<stdio.h> 
#include<stdlib.h> 
int m[10], n;

void citire()
{
	int i;
	printf("Numarul de elemente ale multimii: ");
	scanf("%d", &n);

	printf("\nIntroduceti elementele multimii : \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
	}

	printf("\nElementele multimii sunt: ");
	for (i = 0; i < n; i++)
	{
		printf("%d  ", m[i]);
	}
	printf("\n");

}

void bubblesort()
{
	int i, j, aux;
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (m[i] < m[j])
			{
				aux = m[i];
				m[i] = m[j];
				m[j] = aux;
			}
		}
	}

	printf("\nMultimea in ordine descrescatoare: ");

	for (i = 0; i < n; ++i)
	{
		printf("%d ", m[i]);
	}
	printf("\n");

}

void submultime()
{
	int k,i,suma=0;
	printf("\nIntroduceti numarul de elemente din submultime: ");
	scanf("%d", &k);
	
	if (k >= n)
		printf("Scuze, nu se poate!");
	else
	{
		printf("\nSubmultimea de maxime formata din %d elemente este: ", k);
		for (i = 0; i < k; i++)
		{
			printf("%d ", m[i]);
			suma = suma + m[i];
		}
		printf("\n");
		printf("\nSuma elementelor submultimii este:%d \n ", suma);
	

	}

}


int main()
{
	citire();
	bubblesort();
	submultime();


}