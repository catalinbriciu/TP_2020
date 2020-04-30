#include<stdio.h>
#include<string.h>

int i, j, coloana, linie;

int X[9][9] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
					  {6, 0, 0, 1, 9, 5, 0, 0, 0},
					  {0, 9, 8, 0, 0, 0, 0, 6, 0},
					  {8, 0, 0, 0, 6, 0, 0, 0, 3},
					  {4, 0, 0, 8, 0, 3, 0, 0, 1},
					  {7, 0, 0, 0, 2, 0, 0, 0, 6},
					  {0, 6, 0, 0, 0, 0, 2, 8, 0},
					  {0, 0, 0, 4, 1, 9, 0, 0, 5},
					  {0, 0, 0, 0, 8, 0, 0, 7, 9} };


int search(int *linie, int *coloana)
{
	int x_ok = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			if (X[i][j] == 0)//daca celula este 0 salvam valorile liniei si coloanei
			{
				*linie = i;
				*coloana = j;
				x_ok = 1;
				return x_ok;
			}

	}
	return x_ok;
}
int valid(int n, int l, int c)
{
	int linieprim = (l / 3) * 3;
	int coloanaprim = (c / 3) * 3;
	for (int i = 0; i < 9; i++) //verificam in linie sa nu fie o valoare comuna
	{
		if (X[l][i] == n) //exista valoare egala cu i
		{
			return 0;
		}
	}
	for (int i = 0; i < 9; i++)//verificam in coloana sa nu fie o valoare comuna
	{
		if (X[i][c] == n)//exista valoare egala cu i
		{
			return 0;
		}
	}

	for (i = linieprim; i < linieprim + 3; i++)
	{
		for (j = coloanaprim; j < coloanaprim + 3; j++)
		{
			if (X[i][j] == n)//verificam in submatricea 3x3
				return 0;
		}
	}

}
void print() {
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
		{
			printf("%d ", X[i][j]);
		}
		printf("\n\n");
	}
}
int back()
{
	int i, n, coloana, linie;
	if (search(&linie, &coloana) == 0)
		return 1;
	for (i = 1; i <= 9; i++)
	{
		if (valid(i, linie, coloana))
		{
			X[linie][coloana] = i;
			if (back())
				return 1;
			X[linie][coloana] = 0;
		}
	}
	return 0;
}
int main()
{
	if (back())
		print();
	else
		printf("Nu se poate rezolva\n");
	system("pause");
	return 0;
}