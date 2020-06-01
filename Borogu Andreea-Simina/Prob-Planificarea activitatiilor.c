#include<stdio.h>
#include <stdlib.h>
typedef struct {
	int n, ti[100], tf[100], o[100];
}activitate;
int n, ti[100], tf[100], o[100];
FILE* f, * g;
void citeste()
{
	int minut,ora,i;
	FILE *f, *g;
	f = fopen("activitate.in", "a+t");
	g = fopen("activitate.out", "r+t");
	printf("Dati numarul de activitati n:");
	scanf("%d", &n);
	printf("Introduceti inceputul si sfarsitul activitatiilor:");
	for (i = 0;i <n;i++)
	{
		o[i] = i+1;//transformam timpul in minute
		fscanf(f,"%d %d", &ora,&minut);
		ti[i] = ora * 60 + minut;
		fscanf(f,"%d %d",&ora, &minut);
		tf[i] = ora * 60 + minut;
	}
	fclose(f);
}
void sorteaza()//ordonam activitatiile dupa timpul final
{
	int aux, schimb, i;
	do
	{
		schimb = 0;
		for (i = 0;i<n-1;i++)
			if (tf[o[i]] > tf[o[i + 1]])
			{
				aux = o[i];
				o[i] = o[i + 1];
				o[i + 1] = aux;
				schimb = 1;
			}
	}
	while (schimb);
}
void rezolva()
{
	int ultim, i;
	ultim = 0;
	for (i = 1;i < n;i++)
		if (ti[o[i]] >= tf[o[ultim]])
		{
			fprintf(g,"%d", o[i]);
			ultim = i;
		}
	fprintf(g,"\n");
}
int main()
{
	citeste();
	sorteaza();
	rezolva();
	return 0;
}