#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable:4996)
//bool isPrime(int x)
//{
//	if (x == 0 || x == 1)
//		return false;
//	for (int i = 2; i * i <= x; ++i)
//		if (x % i == 0)
//			return false;
//	return true;
//}
//void findPrimes(int n)
//{
//	if (isPrime(n)) // CASE-I     
//		printf(" %d ", n);
//
//	else if (isPrime(n - 2)) // CASE-II     
//		printf("2 %d ", n - 2);
//
//	else // CASE-III 
//	{
//		printf(" 3 ");
//		n = n - 3;
//		for (int i = 0; i < n; i++) {
//			if (isPrime(i) && isPrime(n - i)) {
//				printf(" %d %d ",i,n - i);
//				break;
//			}
//		}
//	}
//}
//
//
//
//// Driver code 
//int main()
//{
//	int n;
//	printf("n="); scanf("%d", &n);
//	findPrimes(n);
//	return 0;
//}
void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true)
		{
			// Update all multiples of p greater than or  
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked.  
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers 
	for (int p = 2; p <= n; p++)
		if (prime[p])
			printf(" %d ", p);
}

// Driver Program to test above function 
int main()
{
	int n = 30;
	printf("Numerele prime mai mici/egale cu %d sunt: \n", n);

	SieveOfEratosthenes(n);
	return 0;
}