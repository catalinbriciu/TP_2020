#include <stdio.h>
#include <stdlib.h>

int factorial(int val) {
	if (val <= 1)
		return 1;
	else
		return val * factorial(val - 1);

}

int cmmdc(int a, int b) {
	if (b == 0)
		b = a;
	else
		cmmdc(b, a % b);

}

int MannaPnueli(int mp)
{
	if (mp >= 12)
		return mp - 1;
	else
		return MannaPnueli(MannaPnueli(mp + 2));
}

int Fibonacci(int f)
{
	if (!f)
		return 0;
	else if (f== 1)
		return 1;
	else
		return Fibonacci(f - 1) + Fibonacci(f - 2);
}

int InvCifre(int Nr, int NrNou)
{
	if (Nr == 0)
		return NrNou;
	else
		return InvCifre(Nr / 10, NrNou * 10 + Nr % 10);
}

int SumaCifre(int Nr)
{
	if (Nr)
		return Nr % 10 + SumaCifre(Nr / 10);
	else
		return 0;
}

int SumaNrNat(int nr)
{
	if (nr == 1) return 1;
	else return nr + SumaNrNat(nr - 1);
}

int main() {
	int Opt;
	int Nr, NrNou = 0;
	int Fibo;
	int X;
	int Val1, Val2;
	int Value, Factorial;
	do {
	printf("\n1.Cmmdc");
	printf("\n2.Calcul factorial");
	printf("\n3.Manna Pnueli");
	printf("\n4.Fibonacci;");
	printf("\n5.Inversarea cifrelor");
	printf("\n6.Suma cifrelor");
	printf("\n7.Suma primelor n nr. naturale");
	printf("\nOptiunea dv. este:"); scanf("%d", &Opt);
	
		switch (Opt) {
		case 1:printf("\nPrima valoare:"); scanf("%d", &Val1);
			printf("\nA doua valoare:"); scanf("%d", &Val2);
			printf("\nCmmdc al numerelor %d si %d este: %d.\n", Val1, Val2, cmmdc(Val1, Val2));
			break;
		case 2:printf("\nValue is:");
			scanf("%d", &Value);
			Factorial = factorial(Value);
			printf("\nFactorialul valorii este %d.\n", Factorial);
			break;
		case 3:printf("\nx= ");
			scanf("%d", &X);
			printf("\nFunctia Manna-Pnueli f(%d) = %d.\n", X, MannaPnueli(X));
			break;
		case 4:printf("\nn= ");
			scanf("%d", &Fibo);
			printf("\nCalculul functiei Fibonacci f(%d) = %d.\n", Fibo, Fibonacci(Fibo));
			break;
		case 5:printf("\nNumar= ");
			scanf("%d", &Nr);
			printf("\nNumarul %d dupa inversarea cifrelor devine: %d.\n", Nr, InvCifre(Nr, NrNou));
			break;
		case 6:printf("\nNumar= ");
			scanf("%d", &Nr);
			printf("\nSuma cifrelor numarului %d este: %d.\n", Nr, SumaCifre(Nr));
			break;
		case 7:printf("\nn= ");
			scanf("%d", &Nr);
			printf("\nSuma primelor %d numere naturale este: %d.\n", Nr, SumaNrNat(Nr));
			break;
		}
	} while (1);
	system("pause");
	return 0;
}