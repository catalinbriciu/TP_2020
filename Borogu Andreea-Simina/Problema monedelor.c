#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m[100], n, i, schimb, aux, s;
	printf("dati n:");
	scanf("%d", &n);
	printf("dati suma:");
	printf("%d", &s);
	for (i = 1;i <= n;i++)
		printf("m[i]:");
	scanf("%d", &m[i]);
	do
	{
		schimb = 0;
		for(i=1;i<=n;i++)
			if (m[i] < m[i + 1])
			{
				aux = m[i];
				m[i] = m[i + 1];
				m[i + 1] = aux;
				schimb = 1;
			}
	} while (schimb == 1);
	i = 1;
	while (s != 0)
	{
		if (s / m[i])
		{
			printf("%d x\n", m[i]);
			printf("%d\n", s/m[i]);
			s = s % m[i];
		}
		i++;
	}
	return 0;
}