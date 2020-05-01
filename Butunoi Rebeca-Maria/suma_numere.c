#include<stdio.h>
#include<stdlib.h>
int suma(int n)
{
	if (n == 0)
		return 0;
	else
		return n + suma(n - 1);
}
int main()
{
	int n;
	printf("Introduceti numarul: ");
	scanf("%d", &n);
	printf("suma primelor n numere este: %d\n", suma(n));
	return 0;
}