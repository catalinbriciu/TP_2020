#include <stdio.h>
#include <stdlib.h>


int x[100], pus[100], n, m, nr = 0;

void afisare()
{
	for (int i = 1;i <= n + m;i++) 
		if (x[i] == 1)
		    printf("P");
	    else printf("C");
	printf("\n");
	nr++;
}

int cond(int k)
{
	int c = 0, p = 0, i;
	for (i = 1;i <= k;i++)
		if (x[i] == 0) c++;
		else p++;
	if (p > n || c > m) return 0;
	if (k >= 3) if (x[k - 2] == 0 && x[k - 1] == 1 && x[k] == 0) return 0;
	return 1;
}

void back(int k)
{
	for (int i = 1;i >= 0;i--)
	{
		x[k] = i;
		if (cond(k))
			if (k == n + m) afisare();
			else back(k + 1);
	}
}
int main()
{
	printf("Nr de caini:"); scanf("%d", &m);
	printf("Nr de pisici: "); scanf("%d", &n);
	back(1);
	printf("%d", nr);
	system("pause");
	return 0;
}