/*Pentru afisarea verticala a unui numar întreg(câte o cifra pe rând) se poate folosi o stiva în care
se vor depune resturile împartirilor repetate la 10.
Scrieti o functie avînd ca argument un numar întreg, care îl afiseaza vertical, folosind o stiva.

void AfisStivaNr(int number) {
}
123
1
2
3
}
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int st[100];
int vf = 0;
void push(int x)
{
	st[++vf] = x;
}
int pop()
{
	return st[vf--];
}
void AfisStivaNr()
{
	int n, x,inv=0;
	printf("Introduceti nr.: "); scanf("%d", &n);
	while (n != 0)
	{
		inv = inv * 10 + n % 10;
		n = n / 10;
	}
	while (inv != 0)
	{
		x = inv % 10;
		push(x);
		inv = inv / 10;
	}
	for (int i = 1;i <= vf;i++)
	{
		printf("%d\n ", st[i]);
	}

}
int main()
{
	
	AfisStivaNr();
	system("pause");
	return 0;
}