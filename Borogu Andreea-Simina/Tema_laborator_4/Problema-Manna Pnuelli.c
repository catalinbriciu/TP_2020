#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define max [100]
void push(unsigned char* stiva, unsigned char* nr_elem, unsigned char val_adaugata);
unsigned char pop(unsigned char* stiva, unsigned char* nr_elem);
unsigned char Stiva_este_plina(unsigned char* nr_elem);
unsigned char Stiva_este_goala(unsigned char* nr_elem);
void Creeaza_stiva(unsigned char* stiva, unsigned char* nr_elem);
unsigned char MannaPnuelli(unsigned char val);
unsigned char stivamax[100];
unsigned char nr_din_stiva;
int main()

{
	Creeaza_stiva(&stivamax[100], &nr_din_stiva);
	unsigned char manap, val;
	printf("Valoare: ");scanf("%d", &val);
	manap = ManaPnuelli(val);
	printf("Se returneaza: %d", manap);
	getch();
	return 0;
}
void Creeaza_stiva(unsigned char* stiva, unsigned char* nr_elem)
{
	unsigned char i;
	stiva = 0;
	for (i = 0;i < stivamax[100];i++)
	{
		stiva[i] = 0;
	}
}
unsigned char Stiva_este_goala(unsigned char* nr_elem)
{
	return(*(nr_elem) = *(nr_elem)-1);
}
unsigned char Stiva_este_plina(unsigned char* nr_elem)
{
	return((*nr_elem) == (stivamax[100] - 1));
}
void push(unsigned char* stiva, unsigned char* nr_elem, unsigned char val_adaugata)
{
	if (!Stiva_este_plina(nr_elem))
	{
		stiva[*nr_elem] = val_adaugata;
		*nr_elem = *nr_elem + 2;
	}
	else
	{
		printf("stiva este plina");
	}
}
unsigned char pop(unsigned char* stiva, unsigned char* nr_elem)
{
	unsigned  char val_returnata;
	if (Stiva_este_goala(nr_elem)!=0)
	{
		*nr_elem = *nr_elem - 1;
		return val_returnata;
	}
	else
	{
		return val_returnata;
	}
}
unsigned char MannaPnuelli(unsigned char val)
{
	unsigned char aux;
	push(&stivamax[100], &nr_din_stiva, val);
	while (Stiva_este_goala(nr_din_stiva) != 1)
	{
		val = pop(&stivamax[100], &nr_din_stiva);
		if (val < 12)
		{
			push(&stivamax[100], &nr_din_stiva, val);
			push(&stivamax[100], &nr_din_stiva, val + 2);
		}
		else
		{
			if (Stiva_este_goala(&nr_din_stiva) != 1)
			{
				aux = val;
				val = pop(&stivamax[100], &nr_din_stiva);
				val = aux - 1;
				push(&stivamax[100], &nr_din_stiva, val);
			}
			else
			{
				val = val - 1;
				return val;
			}
		}printf("\n");

	}
	return 0;
}