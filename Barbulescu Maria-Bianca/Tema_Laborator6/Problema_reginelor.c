#include <stdio.h>
#include <stdlib.h>
int n, v[100], sol;
void afisare() //afosarea reginei/spatiului
{
	int i, j, x;
	sol++; printf("\nSolutia:%d\n",sol);
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			if (v[i] == j)
		    	printf("R ");
			else printf("_ ");
		printf("\n");
	}
}
int valid(int k) //verificare daca pozitia reginei e corecta
{
	int i;
	for (i = 1;i <= k - 1;i++)
		if ((v[i] == v[k]) || (abs(v[k] - v[i]) == (k - i)))
			return 0;
	return 1;
}
int solutie(int k)//verifica daca s-a gasit o solutie 
{
	if (k == n)
		return 1;
	return 0;
}
void Pb_Reginelor(int k)
{
	int i;
	for (i = 1;i <= n;i++) //se parcurge nr de regine
	{
		v[k] = i;
		if (valid(k) == 1) //daca se gaseste o pozitie corecta
		{
			if (solutie(k) == 1) //se verifica daca e o solitie
				afisare(); //si o afiseaza
			else
				Pb_Reginelor(k + 1); //daca nu,trece la rogina urmatoare
		}
	}
}
int main()
{
	printf("n="); scanf("%d", &n);
	Pb_Reginelor(1);
	system("pause");
	return 0;
}