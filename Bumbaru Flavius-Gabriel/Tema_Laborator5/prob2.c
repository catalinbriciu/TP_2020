#include <stdio.h>
#include <stdlib.h>
#define MAX 25

unsigned char stack[MAX];
unsigned char *SP;

void create(unsigned char *stack ,unsigned char *SP)
{
	unsigned char k; //k - counter
	*SP=0;
	for(k=0;k<MAX;k++)
	{
		stack[k]=0;
	}
}

unsigned char fullstack(unsigned char *SP)
{
	if((*(SP))==MAX-1)
	return 1;
	else return 0;
}

unsigned char emptystack(unsigned char *SP)
{
	if((*(SP))==0)
	return 1;
	else return 0;
}

unsigned char push(unsigned char *stack, unsigned char *SP, unsigned char value)
{
	if(fullstack(&SP)!=1)
	{
		stack[*SP]=value;
		*SP=*SP+1;
	}
	else
	{
		printf("Stiva este plina!");
	}
	
}

unsigned char pop(unsigned char *stack, unsigned char *SP)
{
	unsigned char returned_value=0;
	if(emptystack!=0)
	{
		*SP=*SP-1;
		returned_value=stack[*SP];
		return returned_value;
	}
	else return returned_value;
}

void afisare(unsigned int value)
{
	unsigned int aux;
	while(value)
	{
		aux=value%10;
		push(&stack[0],&SP,aux);
		value=value/10;
	}
	while(emptystack(&SP)!=1)
	{
		value=pop(&stack[0],&SP);
		printf("%d\n",value);
	}
}

int main()
{
	unsigned int value;
	printf("Numar:");
	scanf("%d",&value);
	printf("Stiva:\n");
	
	create(&stack[0],&SP);
	afisare(value);
	return 0;
}
