#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int inversarea_cifrelor(int n)
{
	if (n == 0)
		return 0;
	else 
	{
		printf("%d", n % 10);
		return inversarea_cifrelor(n / 10);
	}
}
int main()
{
	printf("%l", inversarea_cifrelor(12));
	return 0;
}
