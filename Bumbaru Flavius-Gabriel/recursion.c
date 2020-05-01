#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma_n(int n)
{
	if (n < 2) return 1;
	else return n + suma_n(n - 1);
}

int factorial(int n)
{
	int fact;
	if (n == 0) return 1;
	if (n == 1) return 1;
	else
		fact = n * factorial(n - 1);
	return fact;
}

int suma_c(int n)
{
	if (n < 10) return n;
	else return n % 10 + suma_c(n / 10);
}

int mp(int n)
{
	if (n >= 12) return n - 1;
	else return mp(mp(n + 2));
}

int cmmdc(int a, int b)
{
	if (a%b) return cmmdc(b, a%b);
	else return b;
}

int fib(int n)
{
	if (!n) return 0;
	else if (n == 1) return 1;
	else return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n, a, b;
	int opt;
	do
	{
		printf("1 - Suma primelor n numere naturale\n");
		printf("2 - Factorialul unui numar\n");
		printf("3 - Suma cifrelor unui numar\n");
		printf("4 - Manna Pnueli\n");
		printf("5 - CMMDC dintre 2 numere\n");
		printf("6 - Sirul lui Fibonacci\n");
		printf("0 - Iesire\n");
		printf("Alege optiunea: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: printf("n="); scanf("%d", &n);
			printf("Suma primelor %d numere este %d\n", n, suma_n(n));
			break;
		case 2: printf("n="); scanf("%d", &n);
			printf("Factorialul numarului %d este %d\n ", n, factorial(n));
			break;
		case 3: printf("n="); scanf("%d", &n);
			printf("Suma cifrelor numarului %d este %d\n", n, suma_c(n));
			break;
		case 4: printf("n="); scanf("%d", &n);
			printf("Manna Pnueli: %d\n", mp(n));
			break;
		case 5: printf("a="); scanf("%d", &a);
			printf("b="); scanf("%d", &b);
			printf("CMMDC dintre %d si %d este %d\n", a, b, cmmdc(a, b));
			break;
		case 6: printf("n="); scanf("%d", &n);
			printf("Valoarea sirului este %d\n", fib(n));
			break;
		case 0: exit(0);
			break;
		default: printf("Optiune gresita!\n");
			break;

		}
	} while (opt != 0);

	system("pause");
	return 0;
}