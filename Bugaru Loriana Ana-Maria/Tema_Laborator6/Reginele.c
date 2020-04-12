#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

int n, stiva[MAX], solutie;
int Valid(int varf);
int Solution(int varf);
void Print();
void Back(int varf);

int main()
{
	printf("dimensiunea :");
	scanf("%d", &n);
    Back(1);

}

void Back(int varf)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		stiva[varf] = i;
		if (Valid(varf) == 1)
		{
			if (Solution(varf) == 1)
				Print();
			else
				Back(varf + 1);
		}
	}
}
int Valid(int varf)
{
	int i;
	for (i = 1; i <= varf - 1; i++)
		if ((stiva[i] == stiva[varf]) || ((stiva[varf] - stiva[i]) == (varf - i)))
			return 0;
	return 1;
}
int Solution(int varf)
{
	if (varf == n)
		return 1;
	return 0;
}
void Print()

{
	int i, j;
	solutie++;
	printf("Solutia: \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (stiva[i] == j)
				printf(" R ");
			else
				printf(" _ ");
		printf("\n");
	}
	getch();
}
