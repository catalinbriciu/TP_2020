#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n = 15;
int step = 0;

int Manna(int n){
	printf("IN(%d) .... Manna(%d)\n", ++step, n);

	if (n >= 12) return n - 1;
	else return Manna(Manna(n+2));
}
int main(){
	printf("\nManna(%d) = %d\n", Manna(n));
	system("pause");
	return 0;
}
