#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int st[100];
int vf = 0;
void push(int x)
{
	st[++vf] = x;
}
int pop()
{
	return st[vf--];
}
void afiseaza_stiva()
{
	for (int i = 1;i <= vf;i++)
	{
		printf("%d \n ", st[i]);
	}
	
}
int main()
{
	int x;
	printf("Introduceti valoarea variabilei x : ");
	scanf("%d", &x);
	push(x);
	while (st[1] < 12)
	{
		if (st[vf] >= 12 && vf > 0) {
			st[vf - 1] = st[vf] - 1;
			pop();
		}
		else
			push(st[vf] + 2);
	}
	printf(" f(%d)=%d .\n", x, st[vf] - 1);
	system("pause");
	return 0;
}