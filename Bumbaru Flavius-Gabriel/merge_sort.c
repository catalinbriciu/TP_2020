#include <stdio.h>
#include<stdlib.h>
#define max 10

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merging(int li, int k, int ls) {
	int l1, l2, i;

	for (l1 = li, l2 = k + 1, i = li; l1 <= k && l2 <= ls; i++) {
		if (a[l1] <= a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}

	while (l1 <= k)
		b[i++] = a[l1++];

	while (l2 <= ls)
		b[i++] = a[l2++];

	for (i = li; i <= ls; i++)
		a[i] = b[i];
}

void sort(int li, int ls) {
	int k;

	if (li < ls) {
		k = (li + ls) / 2;
		sort(li, k);
		sort(k + 1, ls);
		merging(li, k, ls);
	}
	else {
		return;
	}
}

int main() {
	int i;

	printf("Vectorul inainte de sortare\n");

	for (i = 0; i <= max; i++)
		printf("%d ", a[i]);

	sort(0, max);
	printf("\n");
	printf("Vectorul dupa sortare\n");

	for (i = 0; i <= max; i++)
		printf("%d ", a[i]);
}
