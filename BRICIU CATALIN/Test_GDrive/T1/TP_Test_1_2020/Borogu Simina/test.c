#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int cauta(int ls, int ld)
{
	int x, v[], mij;
	if (ls > ld)
		return 0;
	mij = (ls + ld) / 2;
	if (v[mij] == x)
		return 1;
	else
		if (x > v[mij])
			ls = mij + 1;

		else
			ld = mij - 1;
	return cauta(ls, ld);

}
int liniara(long v[], int n,int nr)
{
	int i;
	for (i = 0;i < n;i++)
		if (v[i] == nr)
			break;
	return v[i];

}
int main()
{
	int nr1, nr3, nr4;
	int nr2;
	int n;
	long v[20000];
	int i;
	printf("dati n:\n");
	scanf("%d", &n);
	for (i = 0; i < n;i++)
		v[i] = 2 * i;

	nr1 = cauta(0, 3);
	printf("%d", nr1);
	nr2 = liniara(v, n, 3);
	printf("%d", nr2);
	nr3 = cauta(0, 19934);
	printf("%d", nr3);
	nr4 = liniara(v, n, 19934);
	printf("%d", nr4);

}