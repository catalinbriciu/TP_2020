#include<stdio.h>
#include<stdlib.h>
#define max 100
unsigned char stack[max];
unsigned char* SP;
void create(unsigned char* stack, unsigned char* SP)
{
	unsigned char contor;
	*SP = 0;
	for (contor = 0; contor < max; contor++)
	{
		stack[contor] = 0;
	}
}
unsigned char FullStack(unsigned char* SP)
{
	if ((*(SP)) == max - 1)
		return 1;
	else return 0;
}
unsigned char EmptyStack(unsigned char* SP)
{
	if ((*(SP)) == 0)
		return 1;
	else return 0;
}
void push(unsigned char* stack, unsigned char  *SP, unsigned char valoare)
{
	if (FullStack(SP) != 1)
	{
		stack[*SP] = valoare;
		*SP = *SP + 1;
	}
	else
	{
		printf("stiva este plina");
	}
}
unsigned char pop(unsigned char* stack, unsigned char* SP)
{
	unsigned char valoare_returnata = 0;
	if (FullStack != 0)
	{
		*SP = *SP - 1;
		valoare_returnata = stack[*SP];
		return valoare_returnata;
	}
	else
		return valoare_returnata;
}
void afisare(unsigned int val)
{
	unsigned int aux;
	while (val)
	{
		aux = val % 10;
		push(&stack[0], SP, aux);
		val = val / 10;
	}
	while (EmptyStack(&SP) != 1)
	{
		val = pop(&stack[0], &SP);
		printf("%d\n", val);
	}
}
int main()
{
	unsigned int val;
	printf("Introduceti numarul: ");
	scanf("%d", &val);
	printf("Stiva este: \n");
	create(&stack[0], &SP);
	afisare(val);
	return 0;
}
