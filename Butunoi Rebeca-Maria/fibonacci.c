#include<stdio.h>
#include<conio.h>
int Fibonacci(int n)
{
	if (n > 2)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else
		return n;
}
int main()
{
	int n;
	printf("Introduceti n: "); scanf("%d", &n);
	printf("Sirul lui Fibo: %d", Fibonacci(n));
	return 0;
	system("pause");

}