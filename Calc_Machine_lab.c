#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


typedef struct {
	unsigned char * data;
	int top;
	int size;
}Stack;


int initialStatus(int size)
{
	Stack* sp = (Stack*)malloc(sizeof(Stack));
	if (sp == NULL) {
		printf("Error--an error has occured in the memory allocation process for the stack pointer \n");
		exit(1);
	}
	sp->data = (int*)malloc(sizeof(int));
	if (sp->data == NULL) {
		printf("Error--an error has occured in the memory allocation process for the data field of the stack pointer \n");
		exit(1);
	}
	sp->top = -1;
	sp->size = size;
	return sp;
}


int emptyStack(Stack* sp)
{
	if (sp->top == -1)
		return 1;
	else
		return 0;
}
//both emptyStack and fullStack functions rely on the value of "top". When top==-1=>stack is empty. top==sp->size-1=>stack is full/overflow 
int fullStack(Stack* sp)
{
	if (sp->top == sp->size - 1)
		return 1;
	else
		return 0;
}

void pushElement(Stack* sp, int value) {

	if (fullStack(sp)) {  //if the stack is full/overflow we'll create a new stack double the size of the old one
		int newStack = (int*)malloc(sizeof(int) * sp->size * 2);
		if (newStack == NULL)
			printf("Error--no memory for the new stack was allocated \n");
		int i = 0;
		for (i = 0; i <= sp->top; i++)
		{
			newStack[&i] = sp->data[i];     //copying the data into the new stack
		}
		free(sp->data);   //free the memory from any old data we had stored
		sp->data = newStack;   //updating the pointer field to the new data contained in the new stack
		sp->size = sp->size * 2;  //doubling the size field accoding to the new size
	}
	sp->data[++sp->top] = value;   //the actual value introduction we need the method for 
}

int popElement(Stack* sp)
{
	if (emptyStack(sp))
		printf("The stack is empty--there is no elemenet to pop \n");
	else
		return sp->data[sp->top--]; //this will return the top value. The value will decrease by one after each iteration
}

void Calc_Machine(Stack* sp)
{
	int i, j, sum = 0, size;
	for (i = 0; i < sp->top; i++)
	{
		if (isdigit(sp->data[i]))
			sum = sum + sp->data[i];
		if (sp->data[i] == '+') {
			while (emptyStack(sp)==0)         //pop all elements
			{
				popElement(sp);
			}
			printf("Sum of the elements is %d", sum);
		}
		if (sp->data[i] == ',')         //pop last element
			popElement(sp);
		if (sp->data[i] == '.') {
			while (emptyStack(sp) == 0)                 //pop all elements leavinf the stack empty
			{ 
				popElement(sp);
			}
			printf("Type in the size of the new stack: ");
			scanf("%d", &size);
			initialStatus(size);                //creating a new stack
		}

	}
	
}

int main()
{
	int count, size, value;
	printf("The size you would like the stack to be: \n");
	scanf("%d", &size);
	Stack* stackPointer = initialStatus(size);
	for (count = 0; count < size - 1; count++)     //reading elements and instantly pushing them into the created stack:
	{
		printf("Element %d: ", count);
		scanf("%d", &value);
		pushElement(stackPointer, value);
	}
	Calc_Machine(stackPointer);
	system("pause");
	return 0;
}