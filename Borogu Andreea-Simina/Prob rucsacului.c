#include <stdio.h>
#include <stdlib.h>

int main()
{
	float c[100], g[100], x[100], C, GMax, p;
	int o[100];
	int i, schimb, aux, n;
	printf("  dati nr de obiecte n=");//citim numarul de obiecte
	scanf("%d", &n);
	printf(" GMax=");//citim greutatea maxima
	scanf("%d", &GMax);
	for (i = 0; i < n; i++)
	{
		printf("intoduceti costul: c[i]=");
		scanf("%d", &c[i]);//citim costul
		printf("intoduceti greutatea: g[i]=");
		scanf("%d", &g[i]);//citim greutatea
	}
	for (i = 0;i < n;i++)
	{
		x[i] = c[i] / g[i];
		o[i] = i;
	}
	//ordonam obiectele descrescator dupa cost
	do
	{
		schimb = 0;
		for (i = 0; i < n; i++)
			if (x[i] < x[i + 1])
			{
				aux = g[i];g[i] = g[i + 1];g[i + 1] = aux;
				aux = c[i];c[i] = c[i + 1];c[i + 1] = aux;
				aux = x[i];x[i] = x[i + 1];x[i + 1] = aux;
				aux = o[i];
				o[i] = o[i + 1];
				o[i + 1] = aux;
				schimb = 1;
			}
	} while (schimb);
	C = 0;i = 1;
	while (GMax > 0 && i <= n)
	{
		if (g[i] <= GMax)
		{
			printf("%d 1\n", o[i]);
			GMax = GMax - g[i];
			C = C + c[i];
		}
		else

		{
			p = GMax / g[i];
			printf("%d %d\n", o[i],p);
			C = C + c[i] * p;
			GMax = 0;
		}
		i++;
	}
	printf("%d", C);
	return 0;
}