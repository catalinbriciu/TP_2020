//Folositi o stiva pentru a simula o masina simpla de adunat.Programul citeste numere reale si le
//pune în stiva.La citirea caracterului '+' se scot numerele din stiva, se aduna si se afiseaza
//rezultatul.
//În plus masina recunoaste urmatoarele instructiuni :
//',' - anuleaza ultima intrare = pop
//'.' - anuleaza toate intrarile(sterge stiva) - createStack
//
//
//+ , ., p, e(p - de la push, e de la exit)
//
//
//p
//2
//p
//3
//p
//4
//+ -- > 9 -- > sterge stiva
//p
//2
//, --->anulat-- > pop din stiva-- > 2.
//
//
//2
//
//
//4
//3
//2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
double St[50]; int  varf = 0, i, n;
void push(int ch) {
	St[++varf] = ch;
}
int pop() {
	varf--;
	return St[varf];
}
int sterge() {
	varf = 0;
	return St[varf];
}

void suma() {
	float s = 0;
	for (int i = 1; i <= varf; i++)
		s = s + St[i];
	sterge();
	printf("Suma=%f", s);
}
void afisare()
{
	int i;
	for (i = varf; i >= 1; i--)
		printf("%d \n", St[i]);
	printf("\n");
}
int main()
{
	char caracter;  int nr, s=0;
	printf("alegeti elementul:\np->push\na->afisare\ne->exit\n+->suma nr\n.->stack erase\n,->pop\n");
	while (1)
	{
		scanf("%c", &caracter);
		if (caracter == 'p') {
			scanf("%d", &nr);
			push(nr);
		}
		if (caracter == 'e')
			exit(0);
		if (caracter == 'a')
			afisare();
		 if (caracter == ',') {
			pop();
			printf("\n");
			afisare();
		}
		 if (caracter == '.') {
			sterge();
			afisare();
		}
		 if (caracter == '+') {
			 suma();
			 afisare();
		 }
	}
	system("pause");
	return 0;
}