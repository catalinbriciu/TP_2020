//1. Se cer toate solutiile de asezare in linie a m caini si n pisici astfel incat sa nu existe o pisica intre doi caini
#include <stdio.h>
#include <stdlib.h>


int x[100], meow, ham, nr = 0;

void afisare()
{
	for (int i = 1; i <= meow + ham; i++)
		if (x[i] == 1)
			printf("P");
		else printf("C");
	printf("\n");
	nr++;
}

int condition(int vf)
{
	int c = 0, p = 0, i;
	for (i = 1; i <= vf; i++)
		if (x[i] == 0) 
			c++;
		else 
			p++;
	if (p > meow || c > ham) return 0;
	if (vf >= 3) if (x[vf - 2] == 0 && x[vf - 1] == 1 && x[vf] == 0) return 0;
	return 1;
}

void Back(int vf)
{
	for (int i = 1; i >= 0; i--)
	{
		x[vf] = i;
		if (condition(vf))
			if (vf == meow + ham) 
				afisare();
			else
				Back(vf + 1);
	}
}
int main()
{
	printf("Nr de caini:"); scanf("%d", &ham);
	printf("Nr de pisici: "); scanf("%d", &meow);
	Back(1);
	printf("%d", nr);
	system("pause");
	return 0;
}

