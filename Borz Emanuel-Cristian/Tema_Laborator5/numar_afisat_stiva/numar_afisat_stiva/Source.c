#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
unsigned char stiva[20]; int varf = 0;

void push(int nr)
{
	stiva[++varf] = nr;

}

void afisare_stiva()
{
	int i;
	printf("\n");
	for (i = 1; i <= varf; i++)
		printf(" %d\n ",stiva[i]);

}
int main()
{
	int numar,invers;
	printf("Nr="); scanf("%d", &numar);
	/*while (numar != 0)
	{
		invers = numar % 10;
		numar = numar / 10;
	}
	printf("%d " ,invers);*/
	while (numar != 0)
	{
		push(numar % 10);
		numar=numar/10 ;
	}
	afisare_stiva();
}