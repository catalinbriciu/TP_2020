#include <stdio.h>

int obj[100], n;
float val[100], kg[100], x[100], G, max;

void  citire()
{
	FILE *f;
	int i;
	f = fopen("in.txt", "rt");
	fscanf(f, " %d%f", &n, &max);
	for (i = 0; i < n; ++i)
	{
		obj[i] = i;
		fscanf(f, "%f%f", &val[i], &kg[i]);
	}
	fclose(f);
}

void sorteaza()
{
	int i, aux, s;
	do
	{
		s = 0;
		for (i = 0; i < n - 1; ++i)
			if (val[obj[i]] / kg[obj[i]] < val[obj[i + 1]] / kg[obj[i + 1]])
			{
				aux = obj[i];
				obj[i] = obj[i + 1];
				obj[i + 1] = aux;
				s = 1;
			}
	} while (s);
}
void rezolva()
{
	int i;
	for (i = 0, G = max; i<n && G>kg[obj[i]]; ++i)
	{
		x[obj[i]] = 1;
		G = G - kg[obj[i]];
	}
	if (i < n && G) {
		x[obj[i]] = G / kg[obj[i]];
		G = 0;
	}

}

void afisare()
{
	FILE *g;
	g = fopen("out.txt", "wt");
	int i;
	for (i = 0; i < n; ++i)
		if (x[i] == 1)
			fprintf(g, "Obj %d\n", i + 1);
		else if (x[i])
			fprintf(g, "Obj %d %f%% \n", i + 1, x[i] * 100);

	fclose(g);
}

int maxain()
{
	citire();
	sorteaza();
	rezolva();
	afisare();
	return 0;
}