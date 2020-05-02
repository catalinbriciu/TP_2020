#include <stdio.h>
#include <stdlib.h>
int Fibonacci(int n)
{
	if (!n)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	/*if (n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return n;*/
}
int main()
{
	int n;
	printf("n= ");
	scanf("%d", &n);
	printf("Calculul functiei Fibonacci f(%d) = %d.\n", n, Fibonacci(n));
	system("pause");
	return 0;
}