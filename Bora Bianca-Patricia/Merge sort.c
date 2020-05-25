/*implementation of merge sort*/

#include <stdio.h>

#include <stdlib.h>



int merge(int arr[], int size, int left[], int ls, int right[], int rs);

int merge_sort(int arr[], int size);



int main(int argc, char* argv[])

{

	int i;

	int arr[] = { 500,450,425,415, 351,375,250,575,257,125 };



	printf("array\n");

	for (i = 0; i < 10; i++)

		printf("%d ", arr[i]);



	merge_sort(arr, 10);



	printf("\nSorted\n");

	for (i = 0; i < 10; i++)

		printf("%d ", arr[i]);



	printf("\n");



	return 0;

}



int merge_sort(int arr[], int size)

{

	/*exit condition*/

	if (size == 1)

		return 0;



	int mid = size / 2;

	int i, j;



	/*create left and right sub arrays*/

	int* left_arr = malloc(mid * sizeof(int));

	int* right_arr;

	right_arr = malloc((size - mid) * sizeof(int));



	/*insert data into left subarray*/

	for (i = 0; i < mid; i++)

		left_arr[i] = arr[i];



	for (i = mid, j = 0; i < size; i++, j++)

		right_arr[j] = arr[i];



	merge_sort(left_arr, mid);

	merge_sort(right_arr, size - mid);

	merge(arr, size, left_arr, mid, right_arr, size - mid);

	free(left_arr);

	free(right_arr);

}



int merge(int arr[], int size, int left[], int ls, int right[], int rs)

{

	int i = 0, j = 0, k = 0;



	while (i < ls && j < rs)

	{

		if (left[i] < right[j])

		{

			arr[k] = left[i];

			i++;

		}

		else if (left[i] > right[j])

		{

			arr[k] = right[j];

			j++;

		}

		else if (left[i] == right[j])

		{

			arr[k++] = left[i];

			arr[k] = right[j];

			i++;

			j++;

		}

		k++;

	}



	while (j < rs)

		arr[k++] = right[j++];

	while (i < ls)

		arr[k++] = left[i++];

}