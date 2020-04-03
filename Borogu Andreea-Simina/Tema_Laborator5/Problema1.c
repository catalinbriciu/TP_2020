#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#define max 100
void create(unsigned char* Stiva, unsigned char* SP);
unsigned char IsStackFull(unsigned char* SP);
unsigned char IsStackEmpty(unsigned char* SP);
void push(unsigned char* Stiva, unsigned char* SP, unsigned char val_adaugata);
unsigned char pop(unsigned char* Stiva, unsigned char* SP);
void afisare_stiva(unsigned int val);
unsigned char Stiva[max];
unsigned char* SP;
void create(unsigned char* Stiva, unsigned char* SP)
{

	unsigned char i;
	*SP = 0;
	for (i = 0;i < max;i++)
	{
		Stiva[i] = 0;
	}
}
unsigned char IsStackFull(unsigned char* SP)
{
	if ((*(SP)) == max - 1)
		return 1;
	else 
		return 0;
}
unsigned char IsStackEmpty(unsigned char* SP)
{
	if ((*(SP)) == 0)
		return 1;
	else
		return 0;
}
void push(unsigned char* Stiva, unsigned char* SP, unsigned char val_adaugata)
{
	if (IsStackFull(&SP) != 1)
	{
		Stiva[*SP] = val_adaugata;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stiva e plina");
	}
}
unsigned char pop(unsigned char* Stiva, unsigned char* SP)
{
	unsigned char val_returnata= 0;
	if (IsStackEmpty != 0)
	{
		*SP = *SP - 1;
		val_returnata = Stiva[*SP];
		return val_returnata;
	}
	else
		return val_returnata;
}
void afisare_stiva(unsigned int val)
{
	unsigned int aux;
	while (val)
	{
		aux = val % 10;
		push(&Stiva[0], &SP, aux);
		val = val / 10;
	}
	while (IsStackEmpty(&SP) != 1)
	{
		val = pop(&Stiva[0], &SP);
		printf("%d\n", val);
	}
}
int main()
{
	unsigned int valoare;
	printf("Numarul: ");
	scanf("%d", &valoare);
	printf("Numarul sub forma de stiva este: \n");
	create(&Stiva[0], &SP);
	afisare_stiva(valoare);
	return 0;
}

