#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int suma = 0;
int Suma(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		suma = n + Suma(n - 1);
}
int main()
{
	printf("%d", Suma(6));
	return 0;
}