#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#pragma warning (disable:4996)

int arr[20];


int maxim(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}

int findMaxSum(int k, int size) {
	int tempSum,maxSum = 0;
	for (int i = 0; i <= size; i++) {
		tempSum = 0;
		for (int j = i; j < i + k; j++) {
			tempSum += arr[j];  
		}
		maxSum = maxim(maxSum, tempSum);
	}
	return maxSum;
}

int main()
{
	int n,k,i;
	printf("Nr elemente multime=");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	printf("Nr elemente submultime=");
	scanf("%d", &k);
	printf("%d",findMaxSum(k, n));


}