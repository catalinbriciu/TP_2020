#include <stdio.h>
#include <stdlib.h>

int Suma(int n)
{
	if (n==0) return 1;
	else return n +Suma(n%10);
}
void print(int n)
{
	int F;
	F = Suma(n);
	printf("%d \n", F);
}
int main()
{
	int n, F;
	printf("Nr n este:"); scanf("%d", &n);
	print(n);
	system("pause");
	return 0;
}