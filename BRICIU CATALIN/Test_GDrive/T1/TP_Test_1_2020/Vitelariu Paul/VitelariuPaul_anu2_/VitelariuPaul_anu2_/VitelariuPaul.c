#include <stdio.h>
int n;
int stiva[5];
int noua_stiva[5];
int j = 0;
void Punctul_1(void)
{
	int i = 0;
	int x;
	x = n;
	while (x != 0)
	{
		stiva[i] = x % 8;
		x = x / 10;
		i++;
	}
	printf("Resturile : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", stiva[i]);
}

void Punctul_2(void)
{
	int i, nr, b, var;

	for (i = 0; i < 5; i++)
	{
		nr = stiva[i];
		var = 0;

	for (b = 0; b < 3; b++)
		if (nr & (1 << b))
			var++;

	if (var > 1)
	{
		noua_stiva[j] = nr;
		j++;
	}
}
	if (j != 0)
	{
		printf("Noua stiva : ");
		for (i = 0; i < j; i++)
			printf("%d ", noua_stiva[i]);
	}
			
}

void Punctul_3(void)
{
	int i;
	int a;
	for (i = 0; i < j; i++)
	{
		a = noua_stiva[i];
		if ((a & (1 << 0)) && (a & (1 << 2)))
			printf("%d ", a);
	}
}

int  main(void)
{
	do
	{
		printf("n="); scanf("%d", &n);
	} while (n < 9999 && n > 100000);

	Punctul_1(); printf("\n");
	Punctul_2(); printf("\n");
	Punctul_3();
	return 0;
}