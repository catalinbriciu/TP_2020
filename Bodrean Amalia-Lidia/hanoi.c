#include<stdio.h>
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		printf("%c %c", a, b);
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%d %c %c", n, a, b);
	}	hanoi(n - 1, c, b, a);
}
int main()
{
	int nr;
	printf("nr:");
	scanf("%d", &nr);
	hanoi(nr, 'A', 'B', 'C');
	return 0;
}