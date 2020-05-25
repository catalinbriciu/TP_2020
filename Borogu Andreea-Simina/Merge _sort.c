#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void merge(int A[], int a, int b, int c)
{
	char B[100];
	int i = a, j = b + 1, k = a, r;
	while ((i <= b) && (j <= c)) //atata timp cat niciun sir nu s a terminat
	{
		if (A[i] <= A[j]) //daca elementul din primul subsir este mai mic sau egal il preluam in sirul interclasat
			B[k] = A[i++];
		else
			B[k] = A[j++];//in caz contrar il preluam pe al doilea sir
		k++;//k-indice in sirul interclasat
	
		if (i > b)//daca primul subsir s a terminat, preluam restul elementelor in subsirul 2
			for (r = j;r <= c;r++)
				k++;
		B[k] = A[r];
		else
			//altfel daca al doilea subsir s a terminat preluam restul elementelor din primul subsir

			for (r = i;r <= b;r++)
				k++;
		B[k] = A[r];
		//mutam elementele interclasate in sirul initial
		for (r = a;r <= c;r++)
			A[r] = B[r];
	}
}
	void merge_sort(char A[], int a, int c)
	{
		int b;
		if (a < c)
		{
			b = (a + c) / 2; //impartim sirul in 2 subsiruri
			merge_sort(A, a, b);//aplicam divide et impera pt cele 2 subsiruri
		}
	}
	int main()
	{ int n,i;
	char A[100];
	printf("Introduceti dimensiunea sirul:");
	scanf("%d", &n);
	printf("Introduceti elementele sirului:\n");
	for (i = 0;i < n;i++)
	{
		printf("A[%d]=", i);
		scanf("%d", A + i);
	}
	merge_sort(A, 0, n - 1);
	printf("Sirul sortat este:");
	for (i = 0;i < n;i++)
	printf("%c", A[i]);
	getch();
	}

