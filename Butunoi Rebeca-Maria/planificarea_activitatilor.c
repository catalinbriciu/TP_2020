#include<stdio.h>

int n = 6, v[50];
int ts[] = { 1, 3, 3, 4, 7, 5 };
int tf[] = { 2, 4, 6, 5, 9, 8 };

void Merge(int li, int ls)
{
	int i, j, k, c = 0;
	i = li; k = (li + ls) / 2; j = k + 1;

	while (i <= k && j <= ls)
	{
		if (tf[i] < tf[j])
			v[c++] = tf[i++];
		else
			v[c++] = tf[j++];
	}
	while (i <= k)
		v[c++] = tf[i++];

	while (j <= ls)
		v[c++] = tf[j++];

	for (i = li; i <= ls; i++)
		tf[i] = v[i - li];
}

void DetI(int li, int ls)
{
	if (li < ls)
	{
		DetI(li, (li + ls) / 2);
		DetI((li + ls) / 2 + 1, ls);
		Merge(li, ls);
	}
}

void Activitati(int s[], int f[], int n)
{
	int i, j;

	printf("Activitatile selectate: \n");
	i = 0;
	printf("%d\n", i + 1);
	for (j = 0; j < n - 1; j++)
	{
		if (ts[j] >= tf[i])
		{
			printf("%d\n", j + 1);
			i = j;
		}
	}
}

int main()
{
	DetI(0, n - 1);
	Activitati(ts, tf, n);

	system("pause");
	return 0;
}