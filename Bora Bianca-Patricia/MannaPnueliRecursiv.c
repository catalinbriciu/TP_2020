#include<stdio.h>
#include<stdlib.h>
int n = 6;
int contor = 0;
int Manna(int n) {
	printf("IN(%d)...Manna(%d)\n", contor++, n);
	if (n >= 12) return n - 1;
	else return Manna(Manna(n + 2));
}
int main() {
	printf("\nManna(%d)=%d\n", n, Manna(n));
	return 0;
}
