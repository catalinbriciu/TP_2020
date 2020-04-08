#include <stdio.h>
#include <stdlib.h>
#define max 25
unsigned char stiva[max];
unsigned char *SP;

void create(unsigned char *stiva,unsigned char *SP)
{
	unsigned char k;
	*SP=0;
	for(k=0;k<max;k++)
		stiva[k]=0;
}

unsigned char fullstack(unsigned char *SP)
{
	if((*(SP))==max-1)
        return 1;
	else
        return 0;
}

unsigned char emptystack(unsigned char *SP)
{
	if((*(SP))==0)
        return 1;
	else
        return 0;
}

unsigned char push(unsigned char *stiva, unsigned char *SP, unsigned char valoare)
{
	if(fullstack(&SP)!=1)
	{
		stiva[*SP]=valoare;
		*SP=*SP+1;
	}
	else
		printf("Stiva este plina!");
}

unsigned char pop(unsigned char *stiva, unsigned char *SP)
{
	unsigned char valret=0;
	if(emptystack!=0)
	{
		*SP=*SP-1;
		valret=stiva[*SP];
		return valret;
	}
	else
        return valret;
}

void afisare(unsigned int val)
{
	unsigned int aux;
	while(val)
	{
		aux=val%10;
		push(&stiva[0],&SP,aux);
		val=val/10;
	}
	while(emptystack(&SP)!=1)
	{
		val=pop(&stiva[0],&SP);
		printf("\n%d",val);
	}
}

int main()
{
	unsigned int val;
	printf("Numar:");
	scanf("%d",&val);
	printf("Stiva:");
	create(&stiva[0],&SP);
	afisare(val);
	return 0;
}
