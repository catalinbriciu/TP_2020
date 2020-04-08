#include <stdlib.h>
#include <stdio.h>

int Ackermann(int x, int y)
{
	if (x != 0 && y != 0)
		Ackermann(x - 1, Ackermann(x, y - 1));
	if (x != 0 && y == 0)
		Ackermann(x - 1, 1);
	if (x == 0 && y != 0)
		return y+ 1;
}
int main()
{
	int a, b, F;
	printf("Introduceti a:");
	scanf("%d", &a);
	printf("Introduceti b:");
	scanf("%d", &b);
	F = Ackermann(a, b);
	printf("F(%d,%d)=%d", a, b, F);
	return 0;
}