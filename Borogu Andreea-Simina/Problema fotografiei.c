#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int i, a[100][100], n, m,f,g;
int nr;
void fill(int i, int j)
{//umple
	if (!a[i][j])
	{
		a[i][j] = 1;
		nr++;
		fill(i - 1, j);//sus
		fill(i + 1, j);//jos
		fill(i, j - 1);//stanga
		fill(i, j + 1);//dreapta
	}
}
int main()
{
	int i, j;
	f=fopen("fill.in","a+t");
	g= fopen("fill.out", "r+t");
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	for (i = 1;i <= m;i++)
		for (j = 1;j <= n;j++)
			fprintf(g, "%d", a[i][j]);
	int max = 0;
	 a[i][j]= 1;
	for (i = 1;i <= m;i++)
		for (j = 1;j <= n;j++)
			if (a[i][j] == 1) {
				a[i][j]++;
				nr = 0;
				fill(i, j, a[i][j]);
				if (max < nr) 
					max = nr;
			}
	fprintf(g, "%d", max);
	for (i = 1;i <= m;i++)
	{
		for (j = 1;j <= n;j++)
			fprintf(g, "%d", a[i][j]);
	}
	fclose(f);
	fclose(g);
	return 0;
}