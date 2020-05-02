#include <stdio.h>
#include <stdlib.h>
int Factorial(int n)
{
	if (n == 0) return 1;
	else return n * Factorial(n - 1);
}
int main()
{
	int n;
	printf("n= ");
	scanf("%d", &n);
	printf("Factorialul primelor %d numere naturale este : %d.\n", n, Factorial(n));
	system("pause");
	return 0;
}