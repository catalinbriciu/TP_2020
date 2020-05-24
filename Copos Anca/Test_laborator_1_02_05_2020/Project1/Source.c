#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int v[20000];
int cautare_binara()
{
	int solutie = -1, x = -1;
	int stg = 0, dr = 20000, mij; 

	while (stg <= dr) 
	{ 
		mij = (stg + dr) / 2;
		if (mij == 4)
		{
			solutie = mij;
			break;
		}
		else if (v[mij] > x) dr = mij - 1;
		else stg = mij + 1;
	}
	return solutie;
}

int cautare_liniara()
{
	int i;
	for (i = 0; i < 20000; i++)
	{
		if (i == 4)
			return 1;
	}
	return 0;  
}

int main()
{
	int i, x = 0;
	time_t start, end;
	int time_taken;
	for (i = 0; i <= 20000; i++)
	{
		v[i] = x;
		x += 2;
	}
	time(&start);
	int rezultat = cautare_binara;
	time(&end);
	double time_taken = double(end - start);
	printf("timpul pt cautare binara : %d", time_taken);
	time(&start);
	int rezultat = cautare_liniara;
	time(&end);
	double time_taken = double(end - start);
	printf("timpul pt cautare binara : %d", time_taken);

}
