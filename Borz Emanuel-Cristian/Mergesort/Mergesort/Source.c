#include<stdio.h>
int Array[20];
#pragma warning (disable:4996)

void Merge(int li, int ls) { // merge = interclasare
	int i, j, k, m[100], c = 0;
	i = li; k = (li + ls) / 2; j = k + 1;
	while (i <= k && j <= ls) { // selecteaza Array[i] sau Array[j]
		if (Array[i] < Array[j])
			m[c++] = Array[i++];
		else
			m[c++] = Array[j++];
	}
	while (i <= k) m[c++] = Array[i++];
	// daca au ramas elemente in stanga
	while (j <= ls) m[c++] = Array[j++];
	// daca au ramas elemente in dreapta
	for (i = li; i <= ls; i++)
		Array[i] = m[i - li];
}
void DI(int li, int ls) {
	if (li < ls) {
		DI(li, (li + ls) / 2);
		DI((li + ls) / 2 + 1, ls);
		Merge(li, ls); //interclasare
	}
}
void readArr(int n) {
	for (int i = 0; i < n; i++)
		scanf("%d", &Array[i]);
}
void printSorted(int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", Array[i]);
}
int main() {
	int n;
	scanf("%d", &n);
	readArr(n);
	DI(0, n - 1);
	printSorted(n);
}
