#include <stdio.h>
#include <conio.h>

int Cmmdc(int a, int b)
{
	if (a == b) return a;
	else
		if (a > b) return Cmmdc(a - b, b);
		else return Cmmdc(a, b - a);
}
void main()
{
	int a, b;
	printf("Introduceti a: ");
	scanf("%d", &a);
	printf("Introduceti b: ");
	scanf("%d", &b);

	if (!a || !b)
		printf("cmmdc(%d,%d) = 1\n", a, b);
	else
		printf("cmmdc(%d,%d) = %d\n", a, b, Cmmdc(a, b));

	return 0;
	system("pause");
}