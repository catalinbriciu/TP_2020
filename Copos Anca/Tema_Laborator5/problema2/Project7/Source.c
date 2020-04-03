#include <stdio.h>
#include <stdlib.h>
int st[50], vf = 0;
void push(int x)
{
	st[vf++] = x;
}
int pop()
{
	vf--;
	return st[vf];
}

int main()
{
	int nr;
	printf("Introduceti numarul : ");
	scanf("%d", &nr);
	while (nr)
	{
		push(nr % 10);
		nr = nr / 10;
	}
	printf("nr afisat vertical : \n");
	while (vf) 
	{
		printf("%d\n", pop());
	}
	system("pause");
	return 0;
}
	