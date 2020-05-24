#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int setflag(int a, int b)
{
	return a | (1 << b);
}

int getflag(int a, int b)
{
	return (1 & (a >> b));
}

void Punct_a(int n)
{
	int i, k = 0, v[20];
	v[k] = 0;
	while (n != 0)
	{
		v[k] = n % 8;
		n = n / 8;
		k++;
		v[k] = 0;
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", v[i]);
		printf("\n");
	}
}

/*
int biti(int v[], int k)
{
	int i, n, z, b, j, a;
	int tab[MAX];
	for (i = 0; i < MAX; i++)
	{
		tab[i] = 0;
	}
	for (z = 0; z < k; z++)
	{
		for (i = 0; i < v[z]; i++)
		{
			tab[v[z] / 8] = setflag(tab[v[z] / 8], v[z] % 8);
		}
	}
	b = 0;
	for (i = 0; i < MAX - 1;i++)
	{
		for (j = 0; j < 7; j++)
		{
			a = getflag(tab[i], j);
			if (a == 1) b++;
		}
	}
	if (b == 2) return 1; else return 0;
}


*/
int main()
{
	int n;
	scanf("%d", &n);
	Punct_a(n);
	/*Punct_b(n);*/
	system("pause");
	return 0;
}