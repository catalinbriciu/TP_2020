#include <stdio.h>
#pragma warning (disable:4996)
int stiva[100]; int varf = 0;

int push(int x)
{
	stiva[varf++] = x;
	return x;
}
int pop()
{
	varf--;
	return stiva[varf];
}


int manna_pnuelli(int x)
{
	if (x >= 12)
	{
		pop();
		return x - 1;
	}
	
	if (pop() < 12) 
			manna_pnuelli(manna_pnuelli(x+2));
	else {
		int z = pop();
		pop();
		push(z - 1);
	}
	
}
int main()
{
	int x;
	printf("X="); scanf("%d", &x);

	printf("%d", manna_pnuelli(x));
	system("pause");
	return 0;
}