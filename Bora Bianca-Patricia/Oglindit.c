#include <stdio.h>
#include <stdlib.h>


long long unsigned Oglindire(long long unsigned  n, long long unsigned p) {
	if (n)
		return Oglindire(n / 10, p * 10 + n % 10);
	return p;
}

int main() {
	long long unsigned  n;
	printf("n = "); scanf("%llu", &n);
	
	printf("Numarul %llu oglindit este: %llu\n", n, Oglindire(n, 0));
	system("pause");
	return 0;
}
