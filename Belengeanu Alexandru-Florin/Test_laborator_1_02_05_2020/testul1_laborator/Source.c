/*
Pentru afisarea verticala a unui numar pentru format din mai multe cifre (e.g. 43252) se poate folosi o stiva 
in care se vor depune resturile impartirilor la x (x fiind baza de numeratie). Pentru fiecare punct de rezolvat 
se va genera o noua functie cu prototipul void Punctul_x(void).

1) Sa se genereze stiva pentru baza 10 pentru nu numar n de 5 cifre citit de la tastatura. (nu e nevoie de afisare)
2) Sa se depuna intr-o noua stiva toate cifrele din stiva de la 1) care sunt divizibile cu 2 folosind operatii pe biti.
3) Sa se extraga si sa se afiseze toate numerele din stiva obtinuta la 2) care au bitul 1 si bitul 2 setat.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int stiva_1[5];
int varf_1 = -1;
int stiva_2[5];
int varf_2 = -1;
int n;
int var;
void push_1(int x)
{
	stiva_1[++varf_1] = x;
}
void push_2(int x)
{
	stiva_2[++varf_2] = x;
}
int pop_1()
{
	return stiva_1[varf_1--];
}
int pop_2()
{
	return stiva_2[varf_2--];
}
void afiseaza_stiva()
{
	for (int i = 0;i <= varf_2;i++)
	{
		printf("%d ", stiva_2[i]);
	}
	printf("\n");
}
void punctul_1()
{
	while (n) { // subpunctul 1
		push_1(n % 10);
		n /= 10;
	}
}
void punctul_2()
{
	while (varf_1 > -1) { // subpunctul 2
		var = pop_1();
		if (!(var & 1))
			push_2(var);
	}
	//afiseaza_stiva();
}
void punctul_3()
{
	while (varf_2 > -1) {
		var = pop_2();
		if (((var & (1 << 2)) != 0) && ((var & (1 << 3)) != 0))
			printf("%d ", var);
	}
}
int main()
{
	printf("n= ");
	scanf("%d", &n);
	punctul_1();
	punctul_2();
	punctul_3();
	system("pause");
	return 0;
}
