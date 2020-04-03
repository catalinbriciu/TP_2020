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
		printf("Memory allocation error. \n");
		exit(1);
	}
	sp->data = (int*)malloc(sizeof(int));
	if (sp->data == NULL) {
		printf("Memory allocation error. \n");
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

	if (fullStack(sp)) {  
		int newStack = (int)malloc(sizeof(int) * sp->size * 2);
		if (newStack == NULL)
			printf("Memory allocation error. \n");
		int i = 0;
		for (i = 0; i <= sp->top; i++)
		{
			newStack[i] = sp->data[i];     
		}
		free(sp->data);   
		sp->data = newStack;   
		sp->size = sp->size * 2;  
	}
	sp->data[++sp->top] = value;   
}

int popElement(Stack* sp){
	if (emptyStack)
		printf("Stack is empty. \n");
	else
		return sp->data[sp->top--]; 
}


int Ackermann(unsigned int m, unsigned int n){
	Stack* sp;
	if (emptyStack) {
		pushElement(sp, m);
		pushElement(sp, n);
	}
	if (n == 0)
		sp->top = m + 1;
	else
		if (m == 0)
		{
			popElement(sp, m);
			popElement(sp, n);
			sp->top = m - 1;
		}
		else
		{
			popElement(sp, m);
			popElement(sp, n - 1);
		}
}

int ManaPnuelli(unsigned int val){
	Stack* sp;
	while (sp->top != -1) { 
		pushElement(sp, val);
		if (val < 12)
			pushElement(sp, val + 2);
		else
		{
			popElement(sp);
			sp->top = val - 1;
		}
	}
}

int main(){
	int count, size, value;
	unsigned int Ack1, Ack2, val;
	char answer[4];
	printf("Size of the stack: \n");
	scanf("%d", &size);
	Stack* stackPointer = initialStatus(size);
	for (count = 0; count < size - 1; count++)   
	{
		printf("Element %d: ", count);
		scanf("%d", &value);
		pushElement(stackPointer, value);
	}
	printf("Ack1= ");
	scanf("%u", &Ack1);
	printf("Ack2= ");
	scanf("%u", &Ack2);
	if (Ack1 == 0)
		printf("Ackermann returns: %u", Ack1 + 1);
	else
		if (Ack2 == 0)
			return (Ackermann(Ack1 - 1, 1));
		else
			return Ackermann(Ack2 - 1, Ackermann(Ack2, Ack1 - 1));
	printf("Would you like to create a new stack for the Mana Pnuelli function? \n");
	scanf("%s", &answer);
	if (strcmp(answer, "Yes") == 0 || strcmp(answer, "yes") == 0)
	{
		for (count = 0; count < size - 1; count++)
		{
			printf("Element %d: ", count);
			scanf("%d", &value);
			pushElement(stackPointer, value);
		}
	}
	printf("Value for Mana Pnuelli= \n");
	scanf("%u", &val);
	ManaPnuelli(val);
	system("pause");
	return 0;
}

/*
I got help from Raul Dolomet with the code, i know what everything does but needed help writing it.
*/