#include<stdio.h>
#include<stdlib.h>
long int factorial(int n)
{
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}
int main()
{
	int n, var;
	printf("Introduceti n= ");
	scanf("%d", &n);

	if (!n)
		printf("0!=1\n");
	else
		printf("%d", factorial(n));

	return 0;
	system("pause");

}