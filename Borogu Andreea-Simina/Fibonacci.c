#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int Fibo(int n)
{
	if (n > 2)
		return Fibo(n - 1) + Fibo(n - 2);
	else
		return n;
}
int main()
{
	printf("%d", Fibo(10));
	return 0;
}