#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
	int* data;
	int top;
	int size;
}Stack;

int initialStatus(int size){
	Stack* sp = (Stack*)malloc(sizeof(Stack));
	if (sp == NULL) {
		printf("Error, an error has occured in the memory allocation process for the stack pointer. \n");
		exit(1);
	}
	sp->data = (int*)malloc(sizeof(int));
	if (sp->data == NULL) {
		printf("Error, an error has occured in the memory allocation process for the data field of the stack pointer. \n");
		exit(1);
	}
	sp->top = -1;
	sp->size = size;
	return sp;
}

int fullStack(Stack* sp) {
	if (sp->top == sp->size - 1)
		return 1;
	else
		return 0;
}

int emptyStack(Stack* sp) {
	if (sp->top == -1)
		return 1;
	else
		return 0;
}


void pushElement(Stack* sp, int value) {
	int i=0;
	if (fullStack(sp)) {  
		int newStack = (int)malloc(sizeof(int) * sp->size * 2);
		if (newStack == NULL)
			printf("Error, no memory for the new stack was allocated. \n");
		
		for (i = 0; i <= sp->top; i++)
		{
			newStack[&i] = sp->data[i];     
		}
		free(sp->data);   
		sp->data = newStack;   
		sp->size = sp->size * 2;  
	}
	sp->data[++sp->top] = value;   
}

int popElement(Stack* sp){
	if (emptyStack)
		printf("The stack is empty, tere is no elemenet to pop. \n");
	else
		return sp->data[sp->top--]; 
}

void Calc_Machine(Stack* sp)
{
	int i, j, sum = 0, *s;
	for (i = 0; i < sp->top; i++)
	{
		if (isdigit(sp->data[i]))
			sum = sum + sp->data[i];
		if (sp->data[i] == '+') {
			while (emptyStack(sp) == 0)
			{
				popElement(sp);
			}
			printf("Sum of the elements is %d", sum);
		}
		if (sp->data[i] == ',')
			popElement(sp);
		if (sp->data[i] == '.') {
			while (emptyStack(sp) == 0)
			{
				popElement(sp);
			}
			printf("Declare the new stack size:"); scanf("%d", &s);
			initialStatus(*s);
		}

	}

}

int main()
{
	int count, size, value;
	printf("The size you would like the stack to be: \n");
	scanf("%d", &size);
	Stack* stackPointer = initialStatus(size);
	for (count = 0; count < size - 1; count++)    
	{
		printf("Element %d: ", count);
		scanf("%d", &value);
		pushElement(stackPointer, value);
	}
	Calc_Machine(stackPointer);
	system("pause");
	return 0;
}
