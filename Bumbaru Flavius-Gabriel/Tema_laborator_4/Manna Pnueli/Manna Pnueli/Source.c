#include <stdio.h>
#include <stdlib.h>
#define MAX 25
int stiva[MAX], varf;

int fullstack()
{
	if (varf == MAX)
	{
		printf("Stiva este plina!");
		return 1;
	}
	return 0;
}

int emptystack()
{
	if (varf == 0)
	{
		printf("Stiva este goala!");
		return 1;
	}
	return 0;
}

int push(int valoare)
{
	if (fullstack())
		return 0;
	varf++;
	stiva[varf] = valoare;
	return 1;
}

int pop()
{
	int aux;
	if (emptystack())
		return 0;
	aux = stiva[varf];
	varf--;
	stiva[varf] = aux - 1;
	return 1;
}

void afisare()
{
	int i;
	printf("Stiva este:\n");
	for (i = 0; i <= varf; i++)
		printf("%d\n", stiva[i]);
}

int main()
{
	int valoare;
	printf("Introduceti valoarea:");
	scanf("%d", &valoare);
	push(valoare);
	while (varf != 0)
	{
		if (stiva[varf] < 12)
		{
			push(stiva[varf] + 2);
			afisare();
		}
		else
		{
			pop();
			afisare();
		}
	}
	printf("\n");
	printf("f(%d)=%d\n", valoare, stiva[varf]);
	system("pause");
	return 0;
}