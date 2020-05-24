#include<stdio.h>
#include<stdlib.h>
char st[20], st2[20], st3[20];
int top = -1, top2 = -1, top3 = -1;
int n;

void push(char x)
{
	st[++top] = x;
}

void push2(char x)
{
	st2[++top2] = x;
}
void push3(char x)
{
	st3[++top3] = x;
}
int pop()
{
	if (top == -1)
		return -1;
	else
		return st[top--];
}

int pop2()
{
	if (top2 == -1)
		return -1;
	else
		return st2[top2--];
}
int pop3()
{
	if (top3 == -1)
		return -1;
	else
		return st3[top3--];
}

void afisare_stiva()
{
	int x;

	while ((x = pop()) != -1)

		printf("%d \n", x);

}

void afisare_stiva2()
{
	int x;

	while ((x = pop2()) != -1)

		printf("%d \n", x);

}
void afisare_stiva3()
{
	int x;

	while ((x = pop3()) != -1)

		printf("%d \n", x);

}

void Punctul_1(void)
{
	while (n > 0)
	{
		push(n % 10);
		n /= 10;
	}
}
void Punctul_2(void)
{

	while ((n = pop()) != -1)
	{
		if ((n & (1 << 0)) != 1)
			push2(n);
	}
}
void Punctul_3(void)
{

	while ((n = pop2()) != -1)
	{
		if (((n & (1 << 1)) == (1 << 1)) && ((n & (1 << 2)) == (1 << 2)))
			push3(n);
	}
}

int main()
{
	printf("introduceti un numar:");
	scanf("%d", &n);
	Punctul_1();
	//afisare_stiva();
	Punctul_2();
	//afisare_stiva2();
	Punctul_3();
	afisare_stiva3();
	return 0;
}