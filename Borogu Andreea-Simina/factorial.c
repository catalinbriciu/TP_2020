#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int fact;
int factorial(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	else
		fact = n * factorial(n - 1);
	return fact;
}
int main()
{
	printf("%d", factorial(6));
	return 0;
}