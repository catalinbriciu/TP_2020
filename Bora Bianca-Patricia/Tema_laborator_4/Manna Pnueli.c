#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

#define max 100
void Push(unsigned char* Stack, unsigned char* SP, unsigned char Push_value);
unsigned char Pop(unsigned char* Stack, unsigned char* SP);
unsigned char IsStackFull(unsigned char* SP);
unsigned char IsStackEmpty(unsigned char* SP);
void Create_Stack(unsigned char* Stack, unsigned char*SP);
unsigned char MannaPnueli(unsigned char Value);
unsigned char Stack[max];
unsigned char* SP;

void Create_Stack(unsigned char* Stiva, unsigned char* SP)
{

	unsigned char count;
	*SP = 0;
	for (count = 0; count < max; count++)
	{
		Stack[count] = 0;
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
	if ((*(SP)) == max - 1)
		return 1;
	else 
		return 0;
}
void Push(unsigned char* Stack, unsigned char* SP, unsigned char PushValue) // se adauga element in varful stivei; 
{
	if (IsStackFull(&SP) != 0)
	{
		Stack[*SP] = PushValue; //se actualizeaza pozitia varfului ca fiind cu una mai sus decat inainte
		*SP = *SP + 1;
	}
	else
	{
		printf("Stack is full");
	}
}
unsigned char Pop(unsigned char* Stack, unsigned char* SP)
{
	unsigned char ValueToReturn = 0;
	if (IsStackEmpty != 1)//if stack is not empty
	{
		*SP = *SP - 1;
		ValueToReturn = Stack[*SP];
		return
			ValueToReturn;
	}
	else
		return ValueToReturn;
}
unsigned char ManaPnuelli(unsigned char Value)
{
	unsigned char v;
	Push(&Stack[0], &SP, Value);
	while (IsStackEmpty(&SP) != 1)
	{
		Value = Pop(&Stack[0], &SP);
		if (Value < 12)
		{
			Push(Stack, &SP, Value);
			Push(Stack, &SP, Value + 2);
		}
		else
		{
			if (IsStackEmpty(&SP) != 1)//daca stiva nu e goala
			{
				v= Value;
				Value = Pop(&Stack[0], &SP);
				Value = v- 1;
				Push(&Stack[0], &SP, Value);
			}
			else //daca stiva e goala
			{
				Value = Value - 1; 
				return Value;
			}
		}
		printf("\n");

	}
}



int main()
{
	unsigned char Value, m;
	printf("Value is");
	scanf("%d", &Value);
	Create_Stack(&Stack[0], &SP);
	m = MannaPnueli;
	printf("Value is %d/n", &m);
	return 0;
}
