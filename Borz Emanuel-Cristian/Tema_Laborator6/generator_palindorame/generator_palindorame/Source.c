#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void CrearePalindroame(int n){
	int copie = n,invers=0;
		while (copie != 0) {
			invers = invers * 10 + (copie%10);
			copie = copie / 10;
		}
		if (invers == n) // inlocuieste o functie isPalindrom()?
			printf(" %d ", n);
}
void Generator(int n){
	for (int i = 1; i <=n; i++)
		CrearePalindroame(i);
 }
int main(){
	int n;
	printf("Afiseaza palindroame pana la numarul: "); scanf("%d", &n);
	Generator(n);
	return 0;
	//#Keep it simple
}
