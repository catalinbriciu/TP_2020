#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Sum = 0;

int NrSum(int n){
	if (n < 10)	{
		return n;
	}
	else{
		return  Sum = n % 10 + NrSum(n / 10);
	}
}
int main(){
	printf("%d", NrSum(2020));
	return 0;
}