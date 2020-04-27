#include<stdio.h>
#include<stdlib.h>
int n = 5;
int step = 0;
int Fact(int n) {
	printf("IN(%d)......Fact(%d)\n", ++step, n);
	if (n > 1) {
		int k = Fact(n - 1);
		printf("OUT...%d\n", n);
		return k * n;
	}
	else return 1;
}
int main() {
	printf("\nFact(%d)=%d\n", n, Fact(n));
	return 0;
}