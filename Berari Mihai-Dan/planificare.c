#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int x, y, k;
}Act;

Act a[20];
int n, s[20], m;

void citire()
{
	int i;
	FILE *f;
	f = fopen("in.txt", "rt");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++) {
		fscanf(f, "%d%d", &a[i].x, &a[i].y);
		a[i].k = i;
	}
	fclose(f);
}
void sorteaza()
{
	int i, j; Act aux;
	for (i = 1; i < n; i++)
		for (j = i; j <= n; j++)
			if (a[i].y >= a[j].y) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
}
void Rez()
{
	int i, j; s[1] = 1; j = 1;
	for (i = 2; i <= n; i++)
		if (a[i].x >= a[s[j]].y) {
			j++;
			s[j] = i;
		}
	m = j;
}

void afisare()
{
	printf("Planificarea activitatilor: \n");
	for (int i = 1; i <= m; i++)
		printf("Activitatea %d incepe la  %d , se termina la %d.\n", a[s[i]].k, a[s[i]].x, a[s[i]].y);

}
int main()
{
	citire();
	sorteaza();
	Rez();
	afisare();
	return 0;
}