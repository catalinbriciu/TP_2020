#include<stdio.h>
#include<stdlib.h>

int i, varf, n, stiva[100], solutie = 0;

char isS, isV = 0;

void Init(int varf) 
{
	stiva[varf] = 0;
}

int Succesor(int varf) 
{
	if (stiva[varf] < n) 
	{ 
		stiva[varf]++; 
        return 1; 
	}

	else 
		return 0;

}



int Valid(int varf) 
{
	for (i = 1; i < varf; i++) 

		if (stiva[i] == stiva[varf]) 
			return 0; 

	return 1;

}

int Solution(varf)
{

	return (varf == n);

}

void Print() 
{

	printf("%d : ", ++solutie);

	for (i = 1; i <= n; i++)

		printf("%d ", stiva[i]);

	printf("\n");

}

void Back()
{
	varf = 1; 
	Init(varf);

	while (varf > 0)
	{

		isS = 0; isV = 0;

		if (varf <= n) 

			do
			{ 

				isS = Succesor(varf);

				if (isS) isV = Valid(varf);

			} while (isS && !isV); 

			if (isS) 

				if (Solution(varf)) 

					Print(); 

				else 
				{ 

					varf++;

					Init(varf); 

				}

			else 

				varf--; 

	}

}

int main() 
{

	n = 4;

	Back();

	return 0;

	system("pause");

	return 0;

}