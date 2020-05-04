#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
void Push(unsigned char* Stack, unsigned char* SP, unsigned char Val);
unsigned char Pop(unsigned char* Stack, unsigned char* SP);
unsigned char IsStackFull(unsigned char* SP);
unsigned char IsStackEmpty(unsigned char* SP);
void CreateStack(unsigned char* Stack, unsigned char* SP);
unsigned char Stack[MAX];
unsigned char* SP;
int Stack1[100], vf1;
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
	if (IsStackEmpty != 0)//daca stiva NU e goala
	{
		*SP = *SP - 1;
		ReturnedValue = Stack[*SP];
		return ReturnedValue;
	}
	else
		return ReturnedValue;
}
void PrintStack(unsigned int Value)
{
	unsigned int x;
	while (Value)
	{
		x = Value % 10;
		Push(&Stack[0], &SP, x);
		Value = Value / 10;
	}
	while (IsStackEmpty(&SP) != 1)
	{
		Value = Pop(&Stack[0], &SP);
		printf("%d\n", Value);
	}
}
void Punctul_1() {
  scanf("%d", &n);//citim numarul
  while (n) {
		Stack1[++vf1] = n % 8;// restul impartirii la 8
		n /= 8;
	}
}
int main()
{
	unsigned int Value;
	printf("Introduceti numarul: ");
	scanf("%d", &Value);
	printf("Afisarea numarului sub forma de stiva: \n");
	CreateStack(&Stack[0], &SP);
	PrintStack(Value);
	Punctul_1();
	return 0;
}
