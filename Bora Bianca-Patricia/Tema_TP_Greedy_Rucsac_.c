#include <stdio.h>

int o[100], N;
float val[100], greu[100], x[100], Gr, M;

void  citeste()
{
	FILE *f;
	int i;
	f = fopen("in.txt", "r");
	fscanf(f, " %d%f", &N, &M);
	for (i = 0; i < N; ++i)
	{
		o[i] = i;
		fscanf(f, "%f%f", &val[i], &greu[i]);
	}
	fclose(f);
}

void sort()
{
	int i, aux, schimb;
	do
	{
		schimb = 0;
		for (i = 0; i < N - 1; ++i)
			if (val[o[i]] / greu[o[i]] < val[o[i + 1]] / greu[o[i + 1]])
			{
				aux = o[i];
				o[i] = o[i + 1];
				o[i + 1] = aux;
				schimb = 1;
			}
	} while (schimb);
}
void rezolva()
{
	int i;
	for (i = 0, Gr = M; i<N && Gr>greu[o[i]]; ++i)
	{
		x[o[i]] = 1;
		Gr -= greu[o[i]];
	}
	if (i < N && Gr) {
		x[o[i]] = Gr/ greu[o[i]];
		Gr = 0;
	}

}

void afisare()
{   
	FILE *g;
	g = fopen("out.txt", "w");
	int i;
	for (i = 0; i < N; ++i)
		if (x[i] == 1) 
			fprintf(g, "Obiectul %d\n", i + 1);
		else if( x[i])
			fprintf(g, "Obiectul %d %f%% \n", i + 1, x[i] * 100);
		
	fclose(g);
}

int main()
{
	citeste();
	sort();
	rezolva();
	afisare();
	return 0;
}