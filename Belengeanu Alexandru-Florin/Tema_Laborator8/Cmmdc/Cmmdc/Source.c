#include <stdio.h>
#include <stdlib.h>
int Cmmdc(int a, int b)
{
	if (b == 0)
		b = a;
	else
		Cmmdc(b, a%b);
}
int main()
{
	int a, b;
	printf("a= ");
	scanf("%d", &a);
	printf("b= ");
	scanf("%d", &b);
	printf("Cmmdc ale numerelor %d si %d este : %d.\n", a, b, Cmmdc(a, b));
	system("pause");
	return 0;
}