#include <stdio.h>
#include <stdlib.h>
void swap(int* var1, int* var2) //interschimbare
{
	int var3 = *var1;
	*var1 = *var2;
	*var2 = var3;
}

int Part(int *array, int low_value, int high_value)
{
	int value = array[high_value];    
	int contor1 = (low_value - 1);

	for (int contor2 = low_value; contor2 <= high_value - 1; contor2++)
	{
		if (array[contor2] < value)
		{
			contor1++;    
			swap(&array[contor1], &array[contor2]);
		}
	}
	swap(&array[contor1 + 1], &array[high_value]);
	return (contor1 + 1);
}

void QuickSort(int *array, int low_value, int high_value)
{
	if (low_value < high_value)
	{
		int value = part(array, low_value, high_value);
		QuickSort(array, low_value, value - 1);
		QuickSort(array, value + 1, high_value);
	}
}


void PrintArray(int *vector, int nr_elem)//afisare stiva
{
	int contor1;
	printf("Vectorul ordonat este: ");
	for (contor1 = 0; contor1 < nr_elem; contor1++)
		printf("%d ", vector[contor1]);
	printf("\n");
}
int main() {
	int nr_elem, *vector, contor1;
	printf("nr_elem= "); scanf("%d", &nr_elem);
	vector = (int*)malloc(sizeof(int) *nr_elem);
	for (contor1 = 0; contor1 < nr_elem; contor1++)
		scanf("%d", &vector[contor1]);
	QuickSort(vector, 0, nr_elem - 1);
	PrintArray(vector, nr_elem);
	return 0;
}