#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);   

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;    
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void QuickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}


void PrintArray(int *v, int n)
{
	int i;
	printf("Vectorul sortat este: ");
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}
int main() {
	int n, *v, i;
	printf("n= "); scanf("%d", &n);
	v = (int*)malloc(sizeof(int) *n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	QuickSort(v, 0, n - 1);
	PrintArray(v, n);
	return 0;
}