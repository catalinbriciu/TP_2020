#include <stdio.h>
#include <stdlib.h>


int v[1000], n, m;

void Init(int k) {
	v[k] = 0;
}
int Succesor(int k) {
	if (v[k] < n) {
		v[k]++;
		return 1;
	}
	return 0;
}

int Valid(int k) {
	int i;
	for (i = 1; i < k; i++)
		if (v[i] == v[k]) return 0;

	return 1;
}

int Solution(int k) {
	return (k == n);
}

void Print() {
	int i;
	printf("%d : ", ++m);
	for (i = 1; i <= n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void Back() {
	int k = 1, isS, isV;
	Init(k);
	while (k > 0) {
		isS = 0; isV = 0;
		if (k <= n)
			do {
				isS = Succesor(k);
				if (isS) isV = Valid(k);
			} while (isS && !isV);
			if (isS)
				if (Solution(k))
					Print();
				else {
					k++;
					Init(k);
				}
			else
				k--;
	}
}

int main() {

	system("cls");
	printf("n = "); scanf("%d", &n);

	Back();
	system("pause");
	return 0;

}
