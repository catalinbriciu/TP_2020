#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)
unsigned char st[20000], n=0;
void push(unsigned char x) {
	st[n] = x;
	n++;
}
int cautare_liniara(int st[], int poz)
{
	int i;
	for (i = 0; i < poz; i++)
		if (i+1 == poz)
			printf("Found at index %d \n in  ", i);

	//double timp = double(end - start);
	//printf("%5lf sec", timp);
 }
int BinarySearch(unsigned char array[], int start, int end, unsigned char searched)
{
	int middle;
	if (start <= end)
	{
		middle = (start + end) / 2;
		if (array[middle] == searched)
		{
			return middle;
		}

		if (array[middle] > searched)
			return BinarySearch(array, start, middle - 1, searched);
		return BinarySearch(array, middle + 1, end, searched);
	}
	return -1;
	//double timp =double(tic - tac);
	//printf("%5lf sec", timp);
}

int main() {
	int i;
	clock_t start, end;
	double timp;
	for (i = 0; i < n; i+=2)
		push(i+2);

	time(&start);
	cautare_liniara(st, st[4]);
	time(&end);
    timp = (double)(end - start);
	printf("%lf sec \n", timp);
	time(&start);
	BinarySearch(st, 2, n, st[4]);
	time(&end);
	timp = (double)(end - start);
	printf("%lf sec \n", timp);

}