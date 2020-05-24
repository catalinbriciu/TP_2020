#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stack[50], varf = -1;


void push(int caracter)
{
	stack[++varf] = caracter;
}

int pop()
{
	return stack[varf--];
}

void show_stack()
{
	printf("Stack : ");
	for (int i = 0; i <= varf; i++)
		printf("\n%d  ", stack[i]);
	
}

void del_stack()
{
	while (varf > -1)
		pop();
}

int punctul_1(int x, int r)
{
	while (x > 0)
	{
		r = x % 10;
		x = x / 10;

	};
}
	

int main()
{
	int x;
	int r=0;
	printf("\nNumarul introdus este:"); scanf("%d", &x);
	punctul_1(x, r);
	push(r);
	show_stack();
	system("pause");
	return 0;
}