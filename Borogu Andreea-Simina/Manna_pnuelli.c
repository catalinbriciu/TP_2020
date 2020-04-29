#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int MannaPnuelli(int n)
{
	if (n >= 12)
		return n - 1;
	else
		return  MannaPnuelli(MannaPnuelli(n + 2));
}
int main()
{
	printf("%d", MannaPnuelli(6));
	return 0;
}