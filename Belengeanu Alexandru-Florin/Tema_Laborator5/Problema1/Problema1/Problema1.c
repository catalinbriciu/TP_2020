/*
	Folositi o stiva pentru a simula o masina simpla de adunat. Programul citeste umere reale si le pune în stiva.
	La citirea caracterului '+' se scot numerele din stiva, se aduna si se afiseaza rezultatul.
	În plus masina recunoaste urmatoarele instructiuni:
		',' - anuleaza ultima intrare
		'.' - anuleaza toate intrarile (sterge stiva)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stiva[50], varf = -1;
void push(int caracter)
{
	stiva[++varf] = caracter;
}
int pop()
{
	return stiva[varf--];
}
void afisare_stiva()
{
	printf("Stiva : ");
	for (int i = 0;i <= varf;i++)
		printf("%d  ", stiva[i]);
	printf("\n");
}
void stergere_stiva()
{
	while (varf > -1)
		pop();
}
void calculeaza_suma()
{
	int suma = 0;
	while (varf > -1) {
		suma += pop();
	}
	printf("Suma elementelor din stiva este egala cu : %d\n", suma);
}
int main()
{
	char caracter[10];
	while (1) {
		printf("Introduceti elementul nr. %d : ", varf + 2);
		scanf("%s", caracter);
		if (strcmp(caracter, ",") == 0 && varf == -1)
			printf("Nu exista nici o intrare precedenta care sa poata fii stearsa.\n");
		else if (strcmp(caracter, ",") == 0 && varf > -1) {
			pop();
			printf("Ultima intrare a fost stearsa cu succes!\n");
			afisare_stiva();
		}
		else if (strcmp(caracter, ".") == 0) {
			stergere_stiva();
			printf("Toate elementele din stiva au fost sterse cu succes!\n");
		}
		else if (strcmp(caracter, "+") == 0)
		{
			calculeaza_suma();
			break;
		}
		else {
			push(atoi(caracter));
			afisare_stiva();
		}
	}
	system("pause");
	return 0;
}