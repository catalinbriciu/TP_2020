#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
# define max 100

typedef struct ackermann_stiva
{
	unsigned char x;
	unsigned char y;
}ackermann_stiva;
unsigned char* SP;
ackermann_stiva stiva[100];
void creare(ackermann_stiva* stiva, unsigned char* SP)
{
	unsigned char i;
	*SP = 0;
	for (i = 0; i <max; i++)
	{
		stiva[i].x = 0;
		stiva[i].y = 0;
	}
}
unsigned char Stiva_este_goala(unsigned char* SP)
{
	if ((*(SP)) == 0)
		return 1;
	else return 0;
}
unsigned char Stiva_este_plina(unsigned char* SP)
{
	if ((*(SP)) == max - 1)
		return 1;
	else
		return 0;
}
void Push(ackermann_stiva *stiva, unsigned char* SP, unsigned char Val_x, unsigned char Val_y)
{
	if (!Stiva_este_plina(SP))
	{
		stiva[*SP].x = Val_x;
		stiva[*SP].y = Val_y;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stiva este plina:");
	}
}
ackermann_stiva Pop(ackermann_stiva* stiva, unsigned char* SP)
{
	ackermann_stiva val_returnata;
	val_returnata.x = 0;
	val_returnata.y = 0;
	if (Stiva_este_goala(&SP) != 1)
	{
		*SP = *SP - 1;
		val_returnata.x = stiva[*SP].x;
		val_returnata.y = stiva[*SP].y;
		return val_returnata;
	}
	else
		return val_returnata;
}
unsigned char Akermann(ackermann_stiva val)
{
	unsigned char Manna_Pnuelli = 0;
	ackermann_stiva pop_val_1;
	ackermann_stiva pop_val_2;
	Push(&stiva[0], &SP, val.x, val.y);
	while (Stiva_este_goala(&SP) != 1)
	{
		pop_val_1 = Pop(&stiva[0], &SP);
		if (pop_val_1.x != 0 && pop_val_1.y != 0)
		{
			Push(&stiva[0], &SP, pop_val_1.x, pop_val_1.y);
			Push(&stiva[0], &SP, pop_val_1.x, pop_val_1.y - 1);
		}

		else
		{
			if (pop_val_1.y == 0)
			{
				Push(&stiva[0], &SP, pop_val_1.x - 1, 1);
			}
			else
			{
				if (pop_val_1.x == 0)
				{
					if (Stiva_este_goala(&SP) == 1)
					{
						return pop_val_1.y + 1;
					}
					else
					{
						pop_val_2 = Pop(&stiva[0], &SP);
						Push(&stiva[0], &SP, pop_val_2.x - 1, pop_val_1.y + 1);
					}
				}
			}
		}

	}

}
int main()
{
	unsigned char valoare;
	ackermann_stiva val;
	val.x = 2;
	val.y = 1;
	printf("Valoarea lui x:");
	scanf("%d", &val.x);
	printf("Valoarea lui y:");
	scanf("%d", &val.y);
	create(&stiva[0], &SP);
	valoare = Akermann(val);
	printf(" Valoarea returnata:\n");
	scanf("%d", valoare);
	system("pause");
	return 0;
}
