
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

 int myTable[20000];


 int cautare_bin(int myTable[], int element) {
	 int start = 0;
	 int end = 19999;
	 while (start <= end) {
		 int mid = (start + end) / 2;
		 if (myTable[mid] == element) {
			 return mid;
		 }
		 else if (element < myTable[mid]) {
			 end = mid - 1;
		 }
		 else {
			 start = mid + 1;
		 }
	 }
	 return -1;
 }
 int cautare_lin(int myTable[], int n, int element);
 {
	 int i;
	 for (i = 0; i < myTable[20000]; i++)
		 if (myTable[i] == element)
			 return i;
	 return -1;
 }
int  main() {
	int element;
	}
	clock_t start, end;
	start = clock();
	printf("%d is found at Index %d \n", element, cautare_bin(myTable, 4));
	end = clock();
	start = clock();

	printf("%d is found at Index %d \n", element, cautare_bin(myTable,19993));
	end = clock();
	start = clock();

	printf("%d is found at Index %d \n", element, cautare_lin(myTable, 4));
	end = clock();
	start = clock();
	printf("%d is found at Index %d \n", element, cautare_in(myTable,19993));
	end = clock();
	printf("timpul de executie este:")
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	system("pause");
	return 0;
}

