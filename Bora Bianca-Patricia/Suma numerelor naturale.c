#include<stdio.h>
#include<stdlib.h>
int sumOfNNumbers(int);

int sumOfNNumbers(int n)

{
	
		if (n == 0)
			
			return 0;
		return n + sumOfNNumbers(n - 1);

}

int main()

{

		printf("sum of first 10 natural numbers: %d\n", sumOfNNumbers(10));///daca n=10

		return 0;

}