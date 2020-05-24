#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
void swap(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}
int partition(int array[], int start, int end) {
	int pivot = array[end];
	int i = (start - 1);
	for (int j = start; j < end; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
		int pivot = partition(array, low, high);
		quickSort(array, low, pivot - 1);
		quickSort(array, pivot + 1, high);
	}
}

void readArray(int array[], int n) {
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);
}

void printArray(int array[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
}

int main() {
	int array[20], n, i;
	printf("Enter number of array elements: ");
	scanf("%d", &n);
	readArray(array, n);
	quickSort(array, 0, n - 1);
	printf("The sorted array is: ");
	printArray(array, n);
	return 0;
	system("pause");
}