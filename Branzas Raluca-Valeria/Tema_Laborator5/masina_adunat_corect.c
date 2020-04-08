#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define max_lung 100
unsigned char Stiva[max_lung];
unsigned char SP;
void Create(unsigned char *Stiva, unsigned char *SP)
{

	unsigned char contor;
	*SP = 0;
	for (contor = 0; contor<max_lung; contor++)
	{
		Stiva[contor] = 0;
	}
}
unsigned char IsStackEmpty(unsigned char *SP)
{
	if ((*(SP)) == 0)
		return 1;
	else
		return 0;
}
unsigned char IsStackFull(unsigned char *SP)
{
	if ((*(SP)) == max_lung - 1)
		return 1;
	else
		return 0;
}
void Push(unsigned char *Stiva, unsigned char *SP, unsigned char Valoare_noua)
{
	if (IsStackFull(SP) != 1)
	{
		Stiva[*SP] = Valoare_noua;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stiva e plina");
	}
}
unsigned char Pop(unsigned char *Stiva, unsigned char *SP)
{
	unsigned char ValReturnata = 0;
	if (IsStackEmpty != 0)//daca stiva NU e goala
	{
		*SP = *SP - 1;
		ValReturnata = Stiva[*SP];
		return ValReturnata;
	}
	else
		return ValReturnata;
}
void afisare(unsigned char Val)
{
	unsigned int val_to_int;
	while (IsStackEmpty(&SP) != 1)
	{
		val_to_int = (Pop(&Stiva[0], &SP)) - '0';
		printf("%d\n", val_to_int);
	}
}
void Suma()
{
	unsigned char Val, s_to_char;
	unsigned int i = 0, s = 0, val_to_int;
	printf("Dati valoarea ");
	scanf("%c", &Val);
	if ((Val >= '0') && (Val <= '9')) {
		//store the number as integer, otherwise store the character
		Val = Val - '0';
	};
	Push(&Stiva[0], &SP, Val);
	while (i < 7)
	{
		Val = Pop(&Stiva[0], &SP);
		if (Val == '.')
		{
			Create(&Stiva[0], &SP);
		}
		else if (Val == ',')
		{
			//Push(&Stiva[0],&SP,Val);
			Val = Pop(&Stiva[0], &SP);
		}
		else if (Val == '+')
		{
			s = 0;
			while (IsStackEmpty(&SP) != 1 && Val != ',' && Val != '.')
			{
				val_to_int = (Pop(&Stiva[0], &SP));
				if (val_to_int >= 0)
				{
					s = s + val_to_int;

				}

			}
			Push(&Stiva[0], &SP, s);
			s = 0;
		}
		else
		{
			Push(&Stiva[0], &SP, Val);
		}
		flushall();
		printf("Dati valoarea ");
		scanf("%c", &Val);
		if ((Val >= '0') && (Val <= '9')) {
			Val = Val - '0';
		};
		Push(&Stiva[0], &SP, Val);
		i++;
	}
	printf("\n\n\n");
	afisare(Val);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Create(&Stiva[0], &SP);
	Suma();
	return 0;
}

