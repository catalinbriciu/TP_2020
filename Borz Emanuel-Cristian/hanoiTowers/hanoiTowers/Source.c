#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
void TurnuriledinHanoi(unsigned char n, unsigned char from, unsigned char to, unsigned char aux)
{
	if (n == 1) {
		printf(" \n Muta discul 1 de la %hhu la %hhu ", from, to);
		return;
	}
	TurnuriledinHanoi(n - 1, from, aux, to);
	printf(" \n Muta discul %hhu de la %hhu la %hhu ", n, from, to);
	TurnuriledinHanoi(n - 1, aux, to, from);
}
int main() {
	unsigned char n;
	printf("Dati numarul de  turnuri ");
	scanf("%hhu", &n);
	TurnuriledinHanoi(n, 1, 2, 3);
}