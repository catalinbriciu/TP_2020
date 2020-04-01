#include <stdlib.h>
#include <stdio.h>

int st_x[50], st_y[50];
int vf_x = 0, vf_y = 0;
void push1(int val)
{
	st_x[++vf_x] = val;
}
void push2(int val)
{
	st_y[++vf_y] = val;
}

void pop1()
{
	st_x[vf_x--];
}
void pop2()
{
	st_y[vf_y--];
}

void afisare()
{
	printf("\n");
	for (int i = 1; i <= vf_x; i++)
		printf("%d ", st_x[i]);
	printf("\n");
	for (int i = 1; i <= vf_y; i++)
		printf("%d ", st_y[i]);
	printf("\n");
}

int main()
{
	int x, y;
	printf("x= ");
	scanf("%d", &x);
	printf("y= ");
	scanf("%d", &y);
	push1(x);
	push2(y);
	afisare();
	while (st_x[1] > 0)
	{
		if (st_x[vf_x] != 0 && st_y[vf_y] != 0)
		{
			push1(st_x[vf_x]);
			push2(st_y[vf_y] - 1);
	    }
		else if (st_y[vf_y] == 0)
		{
			st_x[vf_x] = st_x[vf_x] - 1;
			st_y[vf_y] = 1;
		}
		else if (st_x[vf_x] == 0) 
		{
			st_x[vf_x - 1] = st_x[vf_x - 1] - 1;
			st_y[vf_y - 1] = st_y[vf_y] + 1;
			pop1();
			pop2();
		}
		afisare();
	}
	printf("valoarea fct f(%d,%d) este egala cu : %d .\n", x, y, st_y[vf_y] + 1);
	system("pause");
	return 0;
}