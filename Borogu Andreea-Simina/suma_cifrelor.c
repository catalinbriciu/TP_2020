#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int suma_cif = 0;
int Suma_cifrelor(int n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return  suma_cif=n % 10 + Suma_cifrelor(n / 10);
	}
}
int main()
{
	printf("%d", Suma_cifrelor(1999));
	return 0;
}