#include <stdio.h>
#include <stdlib.h>

#define varfMax 100
int stiva[varfMax], varf = 0;

void push(int x) {
	if (varf != varfMax - 1)
		stiva[++varf] = x;
	else
		printf("stiva este plina!\n");
}

void pop() {
	if (varf)
		--varf;
	else
		printf("Stiva este goala!\n");
}

int main() {
	int x;
	printf("Introduceti x: "); scanf("%d", &x);
	printf("Rezultatul functiei Manna Pnueli este: ");
	push(x);
	do {
		if (stiva[varf] > 11) {
			x = stiva[varf];
			pop();
			pop();
			stiva[varf] = x - 1;
		}
		else
			push(stiva[varf] + 2);
	} while (varf);
	printf("%d\n", stiva[0]);
	system("pause");
}


