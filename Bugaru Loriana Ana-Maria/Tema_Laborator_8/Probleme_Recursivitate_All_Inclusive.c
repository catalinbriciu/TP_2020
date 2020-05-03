#include <stdio.h>
#include <stdlib.h>

int factorial( int numar)
{
	if (numar <= 1 )
		return 1;
	else
	return numar * factorial(numar - 1);
		
	
}

int suma_cifre(int numar)
{
	int sum = 0;
	if (numar < 10)
		return numar;
	return (numar % 10) + suma_cifre(numar / 10);
}

int manna_pnueli(int numar)
{
	if (numar >= 12)
		return numar - 1;
	else
		return manna_pnueli(manna_pnueli(numar + 2));
}

int cmmdc(int numar1, int numar2)
{
	if (numar2 == 0)
		return numar1;
	else
		return cmmdc(numar2, numar1 % numar2);
}

int fibonacci(int numar)
{
	if (numar == 0)
		return 0;
	else if (numar == 1)
		return 1;
	else
		return(fibonacci(numar - 1) + fibonacci(numar - 2));

}

int inversare_cifre(int numar, int invers)
{
	if (numar < 9)
		return invers;
	else
		return inversare_cifre(numar / 10, invers * 10 + numar % 10);
}

int main()
{
	int nr, nr1, nr2, optiune, fact, suma_cif, mannapnueli,div , fibo,invers, inv= 0;
	
	do
	{   
		printf("\n0.Iesire \n");
		printf("1.Factorial \n");
		printf("2.Suma cifrelor \n");
		printf("3.Manna-Pnueli \n");
		printf("4.Cel mai mare divizor comun \n");
		printf("5.Fibonacci \n");
		printf("6.Inversarea cifrelor \n");
		printf("Optiunea dumneavoastra este: \n");
		scanf("%d", &optiune);

		switch (optiune) {
		case 0: exit(0);
			break;

		case 1:
			printf("Introduceti numarul: ");
			scanf("%d", &nr);
			fact = factorial(nr);
			printf("Factorial de %d este: %d \n", nr, fact);
			break;
		case 2:
			printf("Introduceti numarul: ");
			scanf("%d", &nr);
			suma_cif = suma_cifre(nr);
			printf("Suma cifrelor este : %d \n",suma_cif);
			break;
		case 3:
			printf("Introduceti numarul: ");
			scanf("%d", &nr);
			mannapnueli = manna_pnueli(nr);
			printf("Manna-Pnueli(%d)= %d \n", nr, mannapnueli);
			break;
		case 4:
			printf("Numar 1: ");
			scanf("%d", &nr1);
			printf("Numar 2: ");
			scanf("%d", &nr2);
			div = cmmdc(nr1, nr2);
			printf("Cel mai mare divizor comun al numerelor %d si %d este: %d \n", nr1, nr2, div);
			break;
		case 5:
			printf("Introduceti numarul: ");
			scanf("%d", &nr);
			fibo = fibonacci(nr);
			printf("Numarul Fibonacci pentru %d este: %d", nr, fibo);
			break;
		case 6:
			printf("Introduceti numarul: ");
			scanf("%d", &nr);
			invers = inversare_cifre(nr, inv);
			printf("Inversarea cifrelor numarului %d este: %d", nr, invers);
			break;

		default:
			printf("Optiune gresita!\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}