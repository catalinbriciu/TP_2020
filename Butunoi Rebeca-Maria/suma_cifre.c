#include<stdio.h>
#include<conio.h>

int Sum_cifre(int n)
{
	if (!n) return 0;
	else return n % 10 + Sum_cifre(n / 10);
}
void main()
{
	int n;
	printf("Introduceti numarul: ");
	scanf("%d", &n);

	printf("Suma cifrelor numarului este: %d", Sum_cifre(n));
	return 0;
	system("pause");

}