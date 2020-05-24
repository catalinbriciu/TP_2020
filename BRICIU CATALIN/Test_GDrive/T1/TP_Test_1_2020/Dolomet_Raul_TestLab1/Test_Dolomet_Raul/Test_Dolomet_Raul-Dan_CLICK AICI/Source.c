#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


typedef struct {
	unsigned char* data;
	int top;
	int size;
}Stack;


int createStack(int size)
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

void Punctul_8(void);
void twoBits(void);
void extract(void);

void Punctul_8(void)   //thiss is for the first assignment
{
	Stack* sp=NULL;
	int i = 0, value, * arr, contor = 0;;
	printf("VAalue= \n");
	scanf("%d", &value);
	arr = (int*)malloc(sizeof(int));
	while (value) {
		value = (value / 8) * 10 + value % 8;    //resturile impaartirii la 8 se saalveaza in arr[]
		arr[i++] = value;
		contor++;    //cresc un contor ca sa stiu de cate ori am facut aceasta operatie
	}
	createStack(5);
	for (i = 0; i < contor; i++)
	{
		pushElement(sp, arr[i]);    //fiecare valoaare salvata se ia din vector si se pune cu push in stiva
	}

}

int GetBit(int value, int bit)
{
	value = value | (1 << bit);  //simple method to get the value of a certain bit
	return value;
}

void twoBits(void) {
	Stack* sp;
	sp = NULL;
	int one_bits[50] = { 0 }, newarr[50], k=0;
	for (int count = 0; count < sp->top; count++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (GetBit(sp->data[count], j))  //condition to increment the frequency array
				one_bits[sp->data[count]]++;
		}
		
	}
	for (int i = 0; i < sp->top; i++)
	{
		if (one_bits[sp->data[i]] >= 2)   //if there are two or more set bits i'll copy the data in an array
			newarr[k++] = sp->data[i];
	}
	createStack(5);
	for (int i = 0; i < sp->size - 1; i++)
	{
		pushElement(sp, newarr[k++]);  //here  I push the elements from the array into the stack
	}
	printf("These elements are: ");
	for (int i = 0; i < sp->size - 1; i++)
	{
		printf("%d \n", sp->data[i]);
	}
}

void extract(void)
{
	Stack* sp=NULL;
	int i;
	for (i = 0; i, sp->size - 1; i++)
	{
		if ((GetBit(sp->data[i], 0)) && GetBit(sp->data[i], 2))  //this condition only selects the elements care au si bitul 0 si bitul 2 setat
			printf("%d", sp->data[i]);
	}
}

int main()
{
	Stack* sp;
	int size;
	printf("type in the value of the size: ");
	scanf("%d", &size);
	createStack(size);
	Punctul_8();
	twoBits();
	extract();
	system("pause");
	return 0;
}