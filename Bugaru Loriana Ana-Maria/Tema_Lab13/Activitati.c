#include<stdio.h>
#include<stdlib.h>

int N, act[100], in[100], sf[100];

void citire()
{
	int i,ti,tf;
	printf("Numarul de activitati:");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		act[i] = i + 1;
		printf("\nActivitatea nr.%d incepe la: ", i + 1);
		scanf("%d", &ti);
		in[i] = ti;
		printf("si se sfarseste la: ");
		scanf("%d", &tf);
		sf[i] = tf;
	}
	printf("\n");
}

void bubblesort()
{
	int aux, k, i;
	do
	{
		k = 0;
		for (i = 0; i < N - 1; i++)
			if (sf[act[i]] > sf[act[i+1]])
			{
				aux = act[i];
				act[i] = act[i + 1];
				act[i + 1] = aux;
				k = 1;
			}
	} while (k);
}

void solutie()
{
	int j, i=0;
	printf("\nActivitatile ce pot fi indeplinite sunt: ");
	printf("%d ", i+1);
	for (j = 0, i = 1; i < N; i++)
		if (in[act[i]] >= sf[act[j]])
		{
			printf("%d ", act[i] + 1);
			j = i;
		}
	printf("\n");
}

int main()
{
	int i;
	citire();
	bubblesort();
	solutie();

	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("Activitatea nr.%d: %d %d", i + 1, in[i], sf[i]);
		printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;

}