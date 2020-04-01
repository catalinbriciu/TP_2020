#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int stiva[30];
int vf = 1;

void push(int x)
{
	stiva[vf] = x;
	vf++;
}

int pop()
{
	return stiva[vf--];
}

void afisare()
{
	int i;
	for (i = 1; i < vf; i++)
	{
		printf("%d", stiva[i]);
	}
	printf("\n");
}

int main()
{
	int x;
	printf("x="); scanf("%d", &x);
	push(x);
	afisare();
	while (stiva[1] < 12)
	{
		if (stiva[vf - 1] >= 12)
		{
			stiva[vf - 2] = stiva[vf - 1] - 1;
			pop();
		}
		else
			push(stiva[vf - 1] + 2);
		//afisare();

	}
	printf("val fct f( %d ) este: %d \n", x, stiva[vf - 1] - 1);
	system("pause");
	return 0;
}