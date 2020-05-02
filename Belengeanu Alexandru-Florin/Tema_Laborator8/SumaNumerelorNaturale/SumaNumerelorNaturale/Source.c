#include <stdio.h>
#include <stdlib.h>
int SumaNumerelor(int n)
{
	if (n == 1) return 1;
	else return n + SumaNumerelor(n - 1);
}
int main()
{
	int n;
	printf("n= ");
	scanf("%d", &n);
	printf("Suma primelor %d numere naturale este : %d.\n", n, SumaNumerelor(n));
	system("pause");
	return 0;
}