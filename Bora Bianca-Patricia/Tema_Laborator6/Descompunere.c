#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int N, P, V[100], k, S;
int Solutie(int k)
{
	int S = 0;
	for (int i = 1; i <= k; i++)
		S == V[i];
	return (S == N) && (k == P);
}
void Tipar(int k)
{
	int v[100],j;
	for (int j = 1; j <= k - 1; j++)
	{
		printf("%d", &v[j]);
		printf("   +");
	}
	printf(" V[k] == N");
}
int Valid(int k)
{
	int i, d = 2;
	for(i=1;i<=k;i++)
		while (N != 1)
		{
			P = 0;
			while (N % d == 0)
			{
				P++;
				N = N / d;
			}
			if (P != 0) {
				return 1;
				d++;
			}
		}
	return 0;
	}
	
void Descompune_Numar_Back()
{
	
	for (int k = 1; k <= N; k++)
		V[k] = 0;
	k = 1;
	while (k > 0)
	{
		while (V[k] < N + 1 - k)
		{
			V[k] ++;
			if (Valid(k))
			{
				if (Solutie(k))
					Tipar(k);
				else
					if (k < P)
						k++;
			}
			else
				V[k] = N + 1 - k;
		}
		V[k--] = 0;
	}
}
void main(void)
{
	int N, P;
	printf("N");
	printf("S");
	
	Descompune_Numar_Back();
}

