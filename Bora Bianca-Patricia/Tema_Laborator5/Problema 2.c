#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_ELEM 100
void Push(unsigned char* Stack, unsigned char* SP, unsigned char Val);
unsigned char Pop(unsigned char* Stack, unsigned char* SP);
unsigned char IsStackFull(unsigned char* SP);
unsigned char IsStackEmpty(unsigned char* SP);
void CreateStack(unsigned char* Stack, unsigned char* SP);
unsigned char Stack[MAX];
unsigned char* SP;
void CreateStack(unsigned char* Stack, unsigned char* SP)
{

	unsigned char count;
	*SP = 0;
	for (count = 0; count < MAX; count++)
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
	if ((*(SP)) == MAX - 1)
		return 1;
	else
		return 0;
}

void Push(unsigned char* Stack, unsigned char* SP, unsigned char Val)
{
	if (IsStackFull(&SP) != 1)
	{
		Stack[*SP] = Val;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stack is full");
	}
}
unsigned char Pop(unsigned char* Stack, unsigned char* SP)
{
	unsigned char ReturnedValue = 0;
	if (IsStackEmpty != 0)
	{
		*SP = *SP - 1;
		ReturnedValue = Stack[*SP];
		return ReturnedValue;
	}
	else
		return ReturnedValue;
}
int Suma(int Val)
{
	while (IsStackEmpty(&SP) != 1)
	{
		s = 0;
		Val = pop(&Stack[0], &SP);
		s = s + Val;
	}


int GetPriority(char op) {
	switch (op) {
	case ',':
		return 1;
		break
	case '+':
		return 2;
		break;
	case 3: '.'
		return 3;
		break;
	default:
		break;
	}
}


int main() {
	if (GetPriority(s) == 1)
		pop(Stack, SP);
	else
		if (GetPriority(s) == 2)
			return suma(s);
		else
			if (GetPriority(s) == 3)
			{
				while (1);
				Pop(Stack, SP)
			}
}
	system("pause");
	return 0;
