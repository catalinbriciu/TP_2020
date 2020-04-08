#include <stdio.h>
#include <stdlib.h>

int Manna_Pnueli(int);

int main() {
	int x;
	printf("Introduceti x: "); scanf("%d", &x);
	printf("Rezultatul functiei Manna Pnueli este: %d", Manna_Pnueli(x));
}

int Manna_Pnueli(int x) {
	if (x > 11)
		return x - 1;
	return Manna_Pnueli(Manna_Pnueli(x + 2));
}