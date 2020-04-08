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
int adunare(unsigned int val, unsigned char Stiva[], unsigned char op);
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
	return((*SP) == (max- 1));
}
unsigned char IsStackEmpty(unsigned char* SP)
{
	return(*(SP) = *(SP)-1);
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
	unsigned char val_returnata = 0;
	if (IsStackEmpty != 0)
	{
		*SP = *SP - 1;
		val_returnata = Stiva[*SP];
		return val_returnata;
	}
	else
		return val_returnata;
}
int adunare(unsigned int val,unsigned char Stiva[],unsigned char op)
{
	unsigned char i;
	unsigned char suma;
	if(op=='+')
	{
		suma = suma+val;
		push(&Stiva[i], &SP,suma);
		printf("%d\n", suma);
	}
	else
		if(op==',')
	{
		val = pop(&Stiva[max], &SP);
		printf("%d\n", val);
	}
		else 
			if (op == '.')
			{
				val = pop(&Stiva[i], &SP);
				printf("%d\n",val);
			}
}
int main()
{
	unsigned int val,ad;
	unsigned char op,Stiva;
	printf("Dati numerele: ");
	scanf("%d", &val);
	ad=adunare(val,Stiva,op);
	printf("Se returneaza : %d", ad);
	return 0;
}
