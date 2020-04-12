#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

int n, v[MAX], s;
int Valid(int k);
int Solutie(int k);
void Afisare();
void Regine(int k);

int main()
{
	printf("n=");
	scanf("%d", &n);
	Regine(1);

}

void Regine(int k)
{
	int i;
	for (i = 1; i <= n; i++)
	{
	   v[k] = i;
		if (Valid(k) == 1)
		{
			if (Solutie(k) == 1)
				Afisare();
			else
				Regine(k + 1);
		}
	}
}
int Valid(int k)
{
	int i;
	for (i = 1; i <= k - 1; i++)
		if ((v[i] == v[k]) || ((v[k] - v[i]) == (k - i)))
			return 0;
	return 1;
}
int Solutie(int k)
{
	if (k == n)
		return 1;
	return 0;
}
void Afisare()

{
	int i, j;
	s++;
	printf("Solutia: \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (v[i] == j)
				printf(" R ");
			else
				printf(" |");
		printf("\n");
	}
	getch();
}