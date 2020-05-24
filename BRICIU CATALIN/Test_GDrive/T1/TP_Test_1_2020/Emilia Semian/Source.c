#include<stdio.h>
#include<stdlib.h>
void punctul_1(void) {
	int n = 43252;
	int* stiva = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		stiva[i] = n % 10;
		n = n / 10;
		printf("%d\t%d\n", stiva[i], n);
	}
}
int main()
{
	punctul_1();
	return 0;
}