#include<stdio.h>
int a[20];


void Merge(int li, int ls)
{ 
	int i, j, k, m[100], c = 0;
	i = li; k = (li + ls) / 2; j = k + 1;
	while (i <= k && j <= ls)
	{ 
		if (a[i] < a[j])
			m[c++] = a[i++];
		else
			m[c++] = a[j++];
	}
	while (i <= k) m[c++] = a[i++];
	// daca au ramas elemente in stanga
	while (j <= ls) m[c++] = a[j++];
	// daca au ramas elemente in dreapta
	for (i = li; i <= ls; i++)
		a[i] = m[i - li];
}
void Merge_Sort(int li, int ls)
{
	if (li < ls) 
	{
		Merge_Sort(li, (li + ls) / 2);
		Merge_Sort((li + ls) / 2 + 1, ls);
		Merge(li, ls); //interclasare
	}
}
void Print_MS(int n) 
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
int main() 
{
	int n;
	printf("Introduceti numarul de numere: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Merge_Sort(0, n - 1);
	Print_MS(n);
}