#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

int st[20], n, k;

void init()
{
	int i;
	printf("n="); scanf("%d",&n);
	printf("k="); scanf("%d", &k);
	for (i = 1;i <= n;i++)
		st[i] = 0;
}

void afisare(int p)
{
	int j;
	for (j = 1;j <= p;j++)
		printf("%d ",st[j]);
	printf("\n");
}

int valid(int p)
{
	int i, ok;
	ok = 1;
	for (i = 1;i < p;i++)
		if (st[p] == st[i])
			ok = 0;
	return ok;
}

int solutie(int p)
{
	return (p == k);
}

void back(int p)
{
	int val;
	for (val = 1;val <= n;val++)
	{
		st[p] = val;
		if (valid(p))
			if (solutie(p))
				afisare(p);
			else
				back(p + 1);
	}
}

void main()
{
	init();
	back
	(1);
	system("pause");
	return 0;
}