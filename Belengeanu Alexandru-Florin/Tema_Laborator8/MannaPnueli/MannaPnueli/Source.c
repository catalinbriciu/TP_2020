#include <stdio.h>
#include <stdlib.h>
int MannaPnueli(int x)
{
	if (x >= 12)
		return x - 1;
	else
		return MannaPnueli(MannaPnueli(x + 2));
}
int main()
{
	int x;
	printf("x= ");
	scanf("%d", &x);
	printf("Functia Manna-Pnueli f(%d) = %d.\n", x, MannaPnueli(x));
	system("pause");
	return 0;
}