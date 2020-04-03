#include <conio.h>

#include <stdio.h>

#include <stdlib.h>



#define MAX_STACK_SIZE 12u



void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd);

unsigned char Pop(unsigned char * Stack, unsigned char *SP);

unsigned char IsStackFull(unsigned char *SP);

unsigned char IsStackEmpty(unsigned char *SP);

void CreateStack(unsigned char * Stack, unsigned char * SP);

unsigned char ManaPnuelli(unsigned char Val);

unsigned char MyStack[MAX_STACK_SIZE];

unsigned char StackPointer;





int main()

{
	unsigned char Val;

	CreateStack(&MyStack[0u], &StackPointer);

	Val = ManaPnuelli(6);

	printf("%d", Val);

	_getch();

	return 0;

}



void CreateStack(unsigned char * Stack, unsigned char * SP)

{

	unsigned char count;

	*SP = 0u;

	for (count = 0; count < MAX_STACK_SIZE; count++)

	{

		Stack[count] = 0x00;

	}

}



unsigned char IsStackEmpty(unsigned char *SP)

{

	return ((*(SP)) == 0x00u);

}

unsigned char IsStackFull(unsigned char *SP)

{

	return ((*SP) == (MAX_STACK_SIZE - 1u));

}

void Push(unsigned char* Stack, unsigned char * SP, unsigned char ValueToAdd)

{

	if (!IsStackFull(SP))

	{

		Stack[*SP] = ValueToAdd;

		*SP = *SP + 1u;

	}

	else

	{

		/*stack is full*/

	}

}



unsigned char Pop(unsigned char * Stack, unsigned char *SP)

{

	unsigned char ValToReturn = 0xFF;

	if (!IsStackEmpty(SP))

	{

		*SP = *SP - 1;

		ValToReturn = Stack[*SP];

		return ValToReturn;

	}

	else

	{

		return ValToReturn;

	}

}

unsigned char ManaPnuelli(unsigned char Val)

{
	unsigned char MannaPnueliStop = 0;
	unsigned char PopVal_1;
	unsigned char PopVal_2;
	Push(&MyStack[0], &StackPointer, Val);
	while (1)
	{
		PopVal_1 = Pop(&MyStack[0], &StackPointer);

		if (PopVal_1 < 12u)
		{
			Push(&MyStack[0], &StackPointer, PopVal_1);
			Push(&MyStack[0], &StackPointer, PopVal_1 + 2u);
		}
		else
		{
			if (IsStackEmpty(&StackPointer))
			{
				return PopVal_1 - 1u;
			}
			else
			{
				PopVal_2 = Pop(&MyStack[0], &StackPointer);
				Push(&MyStack[0], &StackPointer, PopVal_1 - 1u);
			}
		}
	}

	

	return 0; 

}