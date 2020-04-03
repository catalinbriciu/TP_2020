#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


typedef struct {
	int* data;
	int top;
	int size;
}Stack;

//method prototypes/declaration:

void pushElement(Stack* sp, int value); //*sp will be the stack pointer(to keep track of the objects' addresses)
int popElement(Stack* sp);
int emptyStack(Stack* sp);
int fullStack(Stack* sp);
int intitialStatus(int size);
int AckermannC(unsigned int m, unsigned int n);
int ManaPnuelli(unsigned int val);

//method actual implementation:

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


void pushElement(Stack* sp, int value) {

	if (fullStack(sp)) {  //if the stack is full/overflow we'll create a new stack double the size of the old one
		int newStack = (int*)malloc(sizeof(int) * sp->size * 2);
		if (newStack == NULL)
			printf("Error--no memory for the new stack was allocated \n");
		int i = 0;
		for (i = 0; i <= sp->top; i++)
		{
			newStack[i] = sp->data[i];     //copying the data into the new stack
		}
		free(sp->data);   //free the memory from any old data we had stored
		sp->data = newStack;   //updating the pointer field to the new data contained in the new stack
		sp->size = sp->size * 2;  //doubling the size field accoding to the new size
	}
	sp->data[++sp->top] = value;   //the actual value introduction we need the method for 
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

int popElement(Stack* sp)
{
	if (emptyStack(sp))
		printf("The stack is empty--there is no elemenet to pop \n");
	else
		return sp->data[sp->top--]; //this will return the top value. The value will decrease by one after each iteration
}


int AckermannC(unsigned int m, unsigned int n)    //C-implemented Ackermann function=>Ovidiu+Banias/TP
{
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

int ManaPnuelli(unsigned int val)
{
	Stack* sp;
	while (sp->top != -1) { //the method is ran as long as the stack is not empty
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

int main()
{
	int count, size, value;
	unsigned int Ack1, Ack2, val;
	char answer[4];
	printf("The size you would like the stack to be: \n");
	scanf("%d", &size);
	Stack* stackPointer = initialStatus(size);
	for (count = 0; count < size - 1; count++)     //reading elements and instantly pushing them into the created stack:
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
		printf("AckermannC returns: %u", Ack1 + 1);
	else
		if (Ack2 == 0)
			return (AckermannC(Ack1 - 1, 1));
		else
			return AckermannC(Ack2 - 1, AckermannC(Ack2, Ack1 - 1));
	printf("Do you want to create a new stack for the Mana Pnuelli function? \n"); /*user friendly interogation to determine whether 
																				   they want to create a new stack to work with or not */
	printf("Answer yes in uppercase or lowercase y to create a whole new stack of values to work with \n");
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
	printf("Value to run Mana Pnuelli for= \n");
	scanf("%u", &val);
	ManaPnuelli(val);
	system("pause");
	return 0;
}
/*
Intrebari:
Cum arata conditia scrisa care decide pana cand se executa Ackermann in stiva?
Campul data al pointerului de obiecte din stiva(sp si stackPointer) este pointer. Care e motivul aparititiei erorii
"C2109  subscript requires array or pointer data type" ?
Aceeasi intrebare pt eroaarea "E0142  expression must have pointer-to-object type ".
Mentionez ca campul data din sp si stackPointer este pointer si i-am alocat dinamic memorie cu malloc, totusi cele 2 erori nu dispar.
*/