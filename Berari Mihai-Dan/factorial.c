#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n = 20;
int step = 0;

int Factorial(int n){
	printf("IN(%d) .... Factorial(%d)\n", ++step, n);

	if (n > 1) {
		int k = Factorial(n - 1);
		printf("OUT .... %d\n", n);
		return k * n;
	}
	else return 1;
}
int main(){
	printf("\nFactorial(%d) = %d\n", n, Factorial(n));
	system("pause");
	return 0;
}