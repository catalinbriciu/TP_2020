#include<stdio.h>
#include<stdlib.h>

typedef struct{ 
	int x, y, k;
}activitate;

activitate a[20];
int n, s[20], m;

void citeste()
{
	int i;
	FILE *f;
	f = fopen("in.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++) {
		fscanf(f, "%d%d", &a[i].x, &a[i].y);
		a[i].k = i;
	}
	fclose(f);
}
void sort()
{
	int i, j; activitate aux;
	for (i = 1; i < n; i++)
		for (j = i; j <= n; j++)
			if (a[i].y >= a[j].y) {
				aux = a[i]; 
				a[i] = a[j];
				a[j] = aux; 
			}
}
void greedy()
{
	int i, j; s[1] = 1; j = 1;
	for (i = 2; i <= n; i++)
		if (a[i].x >= a[s[j]].y) {
			j++;
			s[j] = i; }
	m = j;
}

void afiseaza()
{
	printf( "Planificarea activitatilor: \n");
	for (int i = 1; i <= m; i++) 
		printf( "Activitatea %d incepe la ora  %d si se termina la ora %d.\n", a[s[i]].k, a[s[i]].x, a[s[i]].y);
	
}
int main()
{
	citeste(); 
	sort();
	greedy();
	afiseaza();
	return 0;
}