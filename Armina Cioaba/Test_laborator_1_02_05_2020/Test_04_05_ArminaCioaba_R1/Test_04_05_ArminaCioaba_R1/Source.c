#include<stdio.h>
#include<conio.h>

#define max 9

int st1[max];
int vf1 = -1;
int st2[max];
int vf2 = -1;


void Push_2(int val)
{
	if (vf2 == max - 1) {
		printf("Stiva plina!");
	}
	st2[++vf2] = val;


}
int Pop_2()
{

	if (vf2 == -1) {
		return -1;
	}
	else {

		return st2[vf2--];

	}
}
void Push_1(int val)
{
	int i;
	if (vf1 == max - 1) {
		printf("Stiva plina!");
	}
	else
	{
		for (i = 0; i <= max-1; i++)
		{
			st1[++vf1] = val % 8;
			val = val / 8;
		}
	}
		

}
int numarbitisetati(int n)
{
	int c = 0;
	while (n) {
		c = c + (n & 1);
		n >>= 1;
	}
	return c;
}
void bitsetat(int n, int k)
{
	if (n & (1 << (k - 1)))
		printf("%d ",n);
}
void Punctul_1()
{
	int n;
	printf("n=");
	scanf("%d", &n);
	Push_1(n);
}
void Punctul_2()
{
	int i, aux;

	for (i = 0; i <= max - 1; i++)
	{
		aux = numarbitisetati(st1[i]);
		if (aux >= 2)
		{
			Push_2(st1[i]);
		}
	}
}
void Punctul_3()
{
	int i;
	for (i = 0; i <= max - 1; i++)
	{
		bitsetat(st2[i], 0);
		bitsetat(st2[i], 2);
	}
}
int main()
{
	Punctul_1();
	Punctul_2();
	Punctul_3();
	getch();
	return 0;
}