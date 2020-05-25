#include<stdio.h>
#include<stdlib.h>

void hanoi(int N, int a, int b, int c)
{
	if (N == 1)
		printf("Se muta discul de pe tija %d pe tija %d\n", a, b);
	else
	{
		hanoi(N - 1, a, c, b);
		printf("apoi\n");
		printf("Se muta discul de pe tija %d pe tija %d\n", a, b);
		printf("apoi\n");
		hanoi(N - 1, c, b, a);
	}
}

int main()
{
	int N;
	int a = 1, b = 2, c = 3;
	printf("Numarul de discuri:"); scanf("%d", &N);
	printf("\n");
	hanoi(N, a, b, c);
	printf("\n");
	system("pause");
	return 0;
}