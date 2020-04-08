#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int stiva[50];
int varf = 0;
void push(int valoare)
{
	stiva[++varf] = valoare;
}
int pop()
{
	return stiva[varf--];
}
void afiseaza_stiva()
{
	for (int i = 1; i <= varf; i++)
	{
		printf("%d ", stiva[i]);
	}
	printf("\n");
}
int main()
{
	int valoare;
	printf("Introduceti valoarea: ");
	scanf("%d", &valoare);
	push(valoare);
	while (stiva[1] < 12)
	{
		if (stiva[varf] >= 12 && varf > 0)
		{
			stiva[varf - 1] = stiva[varf] - 1;
			pop();
		}
		else
			push(stiva[varf] + 2);
	}
	printf("Valoarea functiei Manna Pnueli f(%d) este egala cu : %d .\n", valoare, stiva[varf] - 1);
	system("pause");
	return 0;
}