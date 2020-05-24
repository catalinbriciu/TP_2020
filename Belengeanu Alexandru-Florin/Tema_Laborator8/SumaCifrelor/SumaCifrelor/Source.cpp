#include <stdio.h>
#include <stdlib.h>
int SumaCifrelor(int n)
{
	if (n)
		return n % 10 + SumaCifrelor(n / 10);
	else
		return 0;
}
int main()
{
	int n;
	printf("n= ");
	scanf("%d", &n);
	printf("Suma cifrelor numarului %d este : %d.\n", n, SumaCifrelor(n));
	system("pause");
	return 0;
}