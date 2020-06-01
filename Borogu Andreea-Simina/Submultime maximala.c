#include<stdio.h>
#include<stdlib.h>
int main()
{
	float M[100], s[100];
	int i, n, m, nr_neg, el_max;
	nr_neg = 0;
	printf("Dati numarul de elemente: n=");
	scanf("%d", &n);
	for (i = 1;i <= n;i++)
	{
		printf("Dati multimea: M[i]=");
		scanf("%d", &M[i]);
		if (M[i] < 0)
			nr_neg++;
	}
	m = 0;
	if (nr_neg != n)
	{
		for(i=1;i<=n;i++)
			if (M[i] > 0)
			{
				m++;
				s[m] = M[i];
			}
	}
	else
	{
		el_max = M[1];
		for (i = 2;i <= n;i++)
			if (M[i] > el_max)
				el_max = M[i];
		m++;
		s[m] = el_max;
	}
	for (i = 1;i <= m;i++)
		printf("%d\n", s[i]);
	return 0;
}