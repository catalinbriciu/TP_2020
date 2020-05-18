#include<stdio.h>
#include<stdlib.h>

void h(int n, char a, char b, char c)
{
	if (n == 1) printf("%c %c\n", a, b);
	else
	{
		h(n - 1, a, c, b);
		printf("%c %c\n", a, b);
		h(n - 1, c, b, a);
	}
}
int main()
{ 
	unsigned n;
	printf("n= "); scanf("%u", &n);
	h(n, 'a', 'b', 'c');
	
	
	return 0;
}