#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int factorial(int n){
	if (n < 2) return 1;
		return n * factorial(n - 1);
}

int suma_cifrelor(int n){
	if (n < 10)
		return n;
    return n % 10 + suma_cifrelor(n / 10);
}

int suma_pana_la_n(int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	else return n + suma_pana_la_n(n - 1); //1+2+3+.....+n = n+(n-1)+....+3+2+1
}

int cmmdc( int x,int y){
	if (y == 0) return x;
		return cmmdc(y, x % y); //metoda resturilor
}

int inversare_nr(int n){
	if (n == 0) exit(0);
	{	printf("%d", n % 10);
		return inversare_nr(n / 10);
	}
}

int manna_pnuelli(int n){
	if (n >= 12) return n - 1;
   return manna_pnuelli(manna_pnuelli(n + 2));
}

int fibonacci(int n){
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
	//printf(" %d ",factorial(4));
	//printf(" %d ", suma_cifrelor(105));
	//printf(" %d ", suma_pana_la_n(10)); 
	//printf(" %d ", inversare_nr(105));
	//printf(" %d ", cmmdc(4,6));
	//printf(" %d ", manna_pnuelli(7));
	//printf(" %d ", fibonacci(10));
}