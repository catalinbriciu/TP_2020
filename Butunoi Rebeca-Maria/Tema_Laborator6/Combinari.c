#include<stdio.h>

int v[100], s;

void Init(int k)
{
	v[k] = 0;
}

int IsSuccesor(int k, int n)
{
	if (v[k] < n)
	{
		v[k]++;
		return 1;
	}
	else
		return 0;
}

int Valid(int k)
{
	int i, c = 0;
	for (i = 1; i < k; i++)
		if (v[i] == v[k])
			return 0;
		else
			c++;
	if (k - c == 1)
		return 1;
	else
		return 0;
}

int Solutie(int k, int m)
{
	if (k == m)
		return 1;
	else
		return 0;
}

void Afisare(int m)
{
	int i;
	s++;
	printf("Solutia %d: ", s);
	for (i = 1; i <= m; i++)
		printf("%d ", v[i]);
	printf("\n");

}


int main()
{
	int n, m, k = 1, isS, isV;

	printf("n: ");
	scanf("%d", &n);
	printf("m: ");
	scanf("%d", &m);

	Init(k);
	while (k > 0)
	{
		isS = 0; isV = 0;
		if (k <= m)
		{
			do
			{
				isS = IsSuccesor(k, n);
				isV = Valid(k);
			} while (isS && !isV);
			if (isS)
			{
				if (Solutie(k, m))
					Afisare(m);
				else
				{
					k++;
					Init(k);
				}
			}
			else
				k--;
		}
	}


	system("pause");
	return 0;
}