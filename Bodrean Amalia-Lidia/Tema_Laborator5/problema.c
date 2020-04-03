#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 100

unsigned char Stack[max];
unsigned char *SP;

void CreateStack(unsigned char *Stiva, unsigned char *SP)
{

	unsigned char count;
	*SP = 0;
	for (count = 0; count < max; count++)
	{
		Stack[count] = 0;
	}
}

unsigned char IsStackFull(unsigned char *SP)
{
	if ((*(SP)) == max - 1)
		return 1;
	else 
		return 0;
}

unsigned char IsStackEmpty(unsigned char *SP)
{
	if ((*(SP)) == 0)
		return 1;
	else 
		return 0;
}

void Push(unsigned char *Stack, unsigned char *SP, unsigned char val)
{
	if (IsStackFull(&SP) != 1)
	{
		Stack[*SP] = val;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stack is full!");
	}
}

unsigned char Pop(unsigned char *Stack, unsigned char *SP)
{
	unsigned char valReturnata = 0;
	if (IsStackEmpty != 0)
	{
		*SP = *SP - 1;
		valReturnata = Stack[*SP];
		return valReturnata;
	}
	else
		return valReturnata;
}

void PritStack(unsigned int Val)
{
	unsigned int aux;
	while (Val)
	{
		aux = Val % 10;
		Push(&Stack[0], &SP, aux);
		Val = Val / 10;
	}
	while (IsStackEmpty(&SP) != 1)
	{
		Val = Pop(&Stack[0], &SP);
		printf("%d\n", Val);
	}
}

int main()
{
	unsigned int Val;
	printf("Dati numarul: "); scanf("%d", &Val);
	printf("Numarul sub forma de stiva este: \n");
	Create(&Stack[0], &SP);
	PrintStack(Val);
	return 0;
}