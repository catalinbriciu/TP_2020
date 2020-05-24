#include <stdio.h>
#include <stdlib.h>
int InversareCifreNumar(int N, int NewN) 
{
	if (N == 0)
		return NewN;
	else
		return InversareCifreNumar(N / 10, NewN * 10 + N % 10);
}
int main()
{
	int N, NewN = 0;
	printf("n= ");
	scanf("%d", &N);
	printf("Numarul %d dupa inversarea cifrelor devine : %d.\n", N, InversareCifreNumar(N, NewN));
	system("pause");
	return 0;
}
