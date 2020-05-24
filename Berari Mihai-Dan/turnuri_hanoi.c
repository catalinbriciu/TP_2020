#include<stdio.h>

void hanoi(int nr_discuri, int start, int stop, int ajutor)
{
	if (nr_discuri == 1)
		printf("Muta un disc de pe tija %d pe tija %d\n", start, stop);
	else
	{
		hanoi(nr_discuri - 1, start, ajutor, stop);
		printf("Muta un disc de pe tija %d pe tija %d\n", start, stop);
		hanoi(nr_discuri - 1, ajutor, start, stop);
	}
}

void main()
{
	int n;
	printf("Dati nr de discuri:"); scanf("%d", &n);
	hanoi(n, 1, 2, 3);
}