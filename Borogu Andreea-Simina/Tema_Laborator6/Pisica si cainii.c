#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int v[100], i, j, k, n, m;
void afisare()
{
	int i;
	for (i = 1;i <= n + m;i++)
		if (v[i] == 1)
		printf("Caini");
		else
		printf("Pisica");
	printf("\n");
}

int cont(int k)
{
	int s, t;
	s = 0;
	t = 0;
	for (i = 1;i <= k;i++)
		if (v[i] == 1)
			s++;
		else
			t++;
	if (k = n + m)
		if (s > n&& t > m)
			return 0;
	if (k > 2 && v[k - 2] == 1 && v[k - 1] == 2 && v[k] == 1)
		return 0;
	else
	return 1;
}

void back(int k)
{
	int i;
	for (i = 1;i <= 2;i++)
	{
		v[k] = i;
		if (cont(k) == 1)
			if (k == n + m)
				afisare();
			else
				back(k + 1);
	}
}

int main()
{
	scanf("%d",&n);
	printf("n");
	scanf("%d", &m);
	printf("m");
	back(1);
	return 0;
}