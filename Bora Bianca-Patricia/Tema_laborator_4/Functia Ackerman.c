#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define MAX_1 
#define MAX_2
typedef struct AckermanStack
{
	unsigned char X;
	unsigned char Y;
};
void Push(AckermanStack* Stack, unsigned char* SP, unsigned char ValueToAdd);
AckermanStack Pop(AckermanStack* Stack, unsigned char* SP);
unsigned char IsStackFull(unsigned char* SP);
unsigned char IsStackEmpty(unsigned char* SP);
void CreateStack(AckermanStack* Stack, unsigned char* SP);
unsigned char Ackerman(AckermanStack Val);
AckermanStack MyStack[MAX_1];
unsigned char StackPointer;
void CreateStack(unsigned char* Stack, unsigned char* SP)
{

	unsigned char c;
	*SP = 0;
	for (c= 0; c < MAX_1; c++)
	{
		Stack[c] = 0;
	}
}
void CreateStack2(unsigned char* Stack2, unsigned char* SP2)
{

	unsigned char c;
	*SP2 = 0;
	for (c = 0; c< MAX_2; c++)
	{
		Stack2[c] = 0;
	}
}
unsigned char IsStackEmpty(unsigned char* SP)
{
	if ((*(SP)) == 0)
		return 1;
	else
		return 0;
}
unsigned char IsStackFull(unsigned char* SP)
{
	if ((*(SP)) == MAX_1 - 1)
		return 1;
	else
		return 0;
}void Push(unsigned char* Stack, unsigned char* SP, unsigned char Value)
{
	if (IsStackFull(&SP) != 1)
	{
		Stiva[*SP] = Value;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stack is full");
	}
}
unsigned char Pop(unsigned char* Stack, unsigned char* SP)
{
	unsigned char Val = 0;
	if (IsStackEmpty != 0)
	{
		*SP = *SP - 1;
		Val = Stack[*SP];
		return Val;
	}
	else
		return Val;
}
void Ackerman(unsigned char* Val)
{
	unsigned char v, i, f;
	Push(&Stack[0], &SP, Val[0]);

	while (IsStackEmpty(&SP) == 0)
	{

		for (i = 1; i < strlen(Val); i++)
		{
			if (Val[i] >= 'a' && Val[i] <= 'z')
			{
				int v = SP2 - '\0';
				Push(&Stack2[0], &SP2, Val[i]);
			}
			else if (Val[i] == '*' || Val[i] == '/' || Val[i] == '(')
			{
				Push(&Stack[0], &SP, Val[i]);

			}
			else if (Val[i] == '+' || Val[i] == '-')
			{
				f = Pop(&Stack[0], &SP);
				while (1)
				{
					if (f == '*' || f == '/')
					{
						Push(&Stack2[0], &SP2, f);

						f = Pop(&Stack[0], &SP);
					}
					else {
						Push(&Stack[0], &SP, f);
						break;
					}
				}
				Push(&Stack[0], &SP, Val[i]);

			}
			else if (Val[i] == ')')
			{
				f = Pop(&Stack[0], &SP);
				while (f != '(')
				{
					Push(&Stack2[0], &SP2, f);
					f = Pop(&Stack[0], &SP);
				}

			}


		}
	}
	printf("Forma poloneza postfixata este: %s\n", Stack2);
}
int main()
{

	unsigned char Val;
	printf("Dati valoarea ");
	scanf("%s", Val);
	CreateStack(&Stack[0], &SP);
	CreateStack2(&Stack2[0], &SP2);
     Ackerman(Val);
	 system("pause");
	return 0;
}

