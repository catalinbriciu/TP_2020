//Pentru afisarea verticala a unui numar pentru format din mai multe cifre (e.g. 43252) se poate
//folosi o stiva in care se vor depune resturile impartirilor la x(x fiind baza de numeratie).
//Pentru fiecare punct de rezolvat se va genera o noua functie cu prototipul
//void Punctul_x(void).
//1) Sa se genereze stiva pentru baza 10 pentru nu numar n de 5 cifre citit de la tastatura. (nu e nevoie de afisare)
//2) Sa se depuna intr - o noua stiva toate cifrele din stiva de la 1) care sunt divizibile cu 2 folosind operatii pe biti.
//3) Sa se extraga si sa se afiseze toate numerele din stiva obtinuta la 2) care au bitul 1 si bitul 2 setat
#include <stdio.h>


int n[10], vf = -1, n2[10], vf2=-1;

void push(int x) {
	vf++;
	n[vf] = x;
}

int pop() {
	return(n[vf--]);
} 
void push2(int x) {
	vf2++;
	n2[vf2] = x;
}

int pop2() {
	return(n2[vf2--]);
}

void  Punctul_1(int a, int x) {
	while (a) {
		push(a % x);
		a = a / x;
	}
} 

void Punctul_2() {
	int aux;
	while (vf != -1) {
		aux = pop();
		if (!(aux &(1 << 0))) {
			push2(aux);
			printf(aux);
		}
	}
}
int main() {
	int a, x;
	printf("Alegeti numarul:");
	scanf("%d", &a);
	Punctul_1(a, 10);
	Punctul_2();
	getch();
	return 0;
}
