#include<stdio.h>
#include<string.h>
int ms[9][9] = { {3, 0, 6, 5, 0, 8, 4, 9, 0},
					  {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0} };
int n, i,j,coloana,linie;
int cautazero(int *linie,int *coloana)
{
	int ok=0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			if (ms[i][j] == 0)//daca celula este 0 salvam valorile liniei si coloanei
			{
				*linie = i;
				*coloana = j;
				ok = 1;
				return ok;
			}

	}
	return ok;
}
int Valid(int n,int l, int c)
{
	int linieprim = (l / 3) * 3;
	int coloanaprim = (c / 3) * 3;
	for (int i = 0; i < 9; i++)//verificam in linie sa nu fie o valoare comuna
	{
		if (ms[l][i] == n)//exista valoare egala cu i
		{
			return 0;
		}
	}
		for (int i = 0; i < 9; i++)//verificam in coloana sa nu fie o valoare comuna
		{
			if (ms[i][c] == n)//exista valoare egala cu i
			{
				return 0;
			}
		}
	
	for (i= linieprim; i < linieprim+3; i++)
	{
		for (j = coloanaprim; j < coloanaprim+3; j++)
		{
			if (ms[i][j] == n)//verificam in submatricea 3x3
				return 0;
		}
	}

}
void Print() {
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
		{
			printf("%d ", ms[i][j]);
		}
		printf("\n\n");
	}
}
int Back()
{
	int i,n,coloana, linie;
	if (cautazero(&linie, &coloana) == 0)
		return 1;
	for (i = 1; i <= 9; i++)
	{
		if (Valid(i, linie, coloana) )
		{
			ms[linie][coloana] = i;
			if (Back())
				return 1;
			ms[linie][coloana] = 0;
		}
	}
	return 0;
}
int main()
{
	if (Back())
		Print();
	else
		printf("Nu se poate rezolva");
	system("pause");
	getch();
	return 0;
}