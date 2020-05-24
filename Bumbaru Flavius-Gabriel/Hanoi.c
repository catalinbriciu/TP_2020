#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write(char a, char b)
{
	printf("Muta discul de pe %c pe %c\n", a, b);
}


void move(int n, char a, char b, char c)
{
	if (n == 1)
	{
		write(a, b);
		return 1;
	}
	else
	{
		move(n - 1, a, c, b);
		write(a, b);
		move(n - 1, c, b, a);
	}
}

int main()
{
	int n;
	printf("Numar de turnuri: ");
	scanf("%d", &n);
	move(n, "S", "M", "D");
	system("pause");
	return 0;
}

//S- stanga
//M- mijloc
//D- dreapta
//n- numar turnuri

