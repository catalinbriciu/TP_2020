#include<stdio.h>
#include<stdlib.h>

int stiva[50];
int varf;

void push(int x)
{
	varf++;
	stiva[varf] = x;
}
int pop()
{
	varf--;
	return stiva[varf + 1];
}
int peek()
{
	return stiva[varf];
}

int main()
{
	int x;
	int f = 0;

	printf("\n x=");
	scanf("%d", &x);
	push(x);
	while (varf > 0)
	{
		x = peek();
		if (x >= 12)
		{
			f = x - 1;
			pop();
			pop();
			push(f);
		}
		else
		{
			push(x + 2);
		}
	}
	printf("f=%d\n", f);
	system("pause");
	return 0;
}