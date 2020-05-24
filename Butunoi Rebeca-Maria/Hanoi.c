#include<stdio.h>
void towers(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("\Muta discul 1 de pe tija %c pe tija %c", a, b);
		return;
	}
	towers(n - 1, a, c, b);
	printf("\nMuta discul %d de pe tija %c pe tija %c", n, a, b);
	towers(n - 1, c, b, a);
}
int main()
{
	int nr;
	printf("nr:");
	scanf("%d", &nr);
	printf("The sequence of moves involved in the Tower of Hanoi are:\n");
	towers(nr, 'A', 'B', 'C');
	return 0;
}