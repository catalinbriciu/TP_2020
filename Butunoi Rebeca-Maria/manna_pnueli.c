#include<stdio.h>
#include<stdlib.h>
int Manna_P(int n)
{
	if (n >= 12)
		return (n - 1);
	else return Manna_P(Manna_P(n + 2));
}
int main()
{
	int x;
	printf("Introduceti x: "); scanf("%d", &x);
	printf("Rezultatul este: %d", Manna_P(x));
	return 0;
	system("pause");
}