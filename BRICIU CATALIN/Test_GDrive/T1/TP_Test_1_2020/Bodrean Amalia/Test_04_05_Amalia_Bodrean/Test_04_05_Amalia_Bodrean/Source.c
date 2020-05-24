#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#define n 5
#pragma warning (disable:4996)


int stiva[n], varf = -1;

void Push(int x)
{
	if (varf == n - 1)
		printf("Overflow");
	else
		stiva[++varf] = x;
}

void Pop(int y)
{
	if (varf == -1)
		printf("Underflow");
	else
		return stiva[varf--];
}

void afisare(int i)
{
	for (i = 1; i <= varf; i++)
		printf("%d", stiva[i]);
	printf("\n\n");
}


int main()
{
	int nr, i, aux=0;
	printf("Introduceti numarul: "); scanf("%d", &nr);
	for (i = 1; i <= 5; i++)
	{
		aux = nr % 10;
		nr = nr / 10;
		Push(aux);
	}
	while(varf!=-1)
	{
		Pop(stiva[varf]);
		if (stiva[varf] >> 1==0)
			Push(stiva[varf]);
	}
	system("pause");
	return 0;
}