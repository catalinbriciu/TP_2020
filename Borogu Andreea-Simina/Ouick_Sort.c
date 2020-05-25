#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int a[100], n;
void Quick_Sort(int x, int y)
{

	if (x < y)
	{
		int i, j, aux, m;
		m = a[(x + y) / 2];
		i = x - 1;
		j = y + 1;
		while (i < j)
		{
			   j--;
			while (a[j] > m);
		       i++;
			while (a[i] < m);
			if (i < j)
			{
				int aux;
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
		Quick_Sort(x, j);
		Quick_Sort(j + 1, y);
	}
}

int main()
{
	int i,n;
	printf("introduceti n:");
	scanf("%d", &n);
	for (i = 1;i <= n;i++)
		printf("a[i]");
	scanf("%d", &a[i]);
	Quick_Sort(1, n);
	for (i = 1;i <= n;i++) 
		printf("a[i]");
	return 0;
	system("pause:");
}