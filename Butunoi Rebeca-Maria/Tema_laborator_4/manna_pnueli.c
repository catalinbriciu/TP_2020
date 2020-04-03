#include<stdio.h>
#include<stdlib.h>

int st[20];
int vf;
void push(int x)
{

	vf++;
	st[vf] = x;
	return x;
}
int pop()
{

	vf--;
	return st[vf + 1];
}
int peek()
{
	return st[vf];
}
int main()
{
	int x, f;
	printf("Introduceti x: ");
	scanf("%d", &x);
	push(x);
	while (vf > 0)
	{
		x = peek(x);
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
	printf("%d ", st[0]);

	system("pause");
	return 0;
}
