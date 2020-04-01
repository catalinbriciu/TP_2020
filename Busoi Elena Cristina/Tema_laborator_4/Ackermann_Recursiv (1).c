#include <stdio.h>
#include <stdlib.h>

unsigned Ackermann(int, int);

int main() {
	unsigned x, y;
	printf("Introduceti x: "); scanf("%u", &x);
	printf("Introduceti y: "); scanf("%u", &y);
	printf("Rezultatul functuiei Ackermann %d\n", Ackermann(x, y));
	system("pause");
}

unsigned Ackermann(unsigned x, unsigned y) {
	if (!x)
		return y + 1;
	else if (!y)
		return Ackermann(x - 1, 1);

	return Ackermann(x - 1, Ackermann(x, y - 1));
}

