#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n = 10;
int step = 0;

int Fibo(int n){
	printf("IN .... %d\n", ++step);

	if (n > 2) return Fibo(n - 1) + Fibo(n - 2);
	else return 1;
}
int main(){
	printf("Fibo(%d) = %d\n", n, Fibo(n));
	system("pause");
	return 0;
}