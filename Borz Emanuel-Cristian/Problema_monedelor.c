#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000
void retrage_bani()
{
	unsigned char numar_bacnote[8], suma_ceruta;
	int numar_cereri, i;
	FILE* f, * g;
	f = fopen("atm.in", "a+t"); // creare si deschidere fisier
	g = fopen("atm.out", "w+t");
	for (i = 1; i <= 8; i++) // citire numar de bacnote
		fscanf(f, "%hhu", &numar_bacnote[i]);
	fscanf(f, "%hhu", &numar_cereri);
	for (i = 1; i <= numar_cereri; i++) {
		fscanf(f, "%hhu", &suma_ceruta);

		if (suma_ceruta / 500 <= numar_bacnote[8]) {
			numar_bacnote[8] = numar_bacnote[8] - suma_ceruta / 500;
			suma_ceruta = suma_ceruta % 500; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 500 * numar_bacnote[8];
			numar_bacnote[8] = 0;
		}

		if (suma_ceruta / 200 <= numar_bacnote[7]) {
			numar_bacnote[7] = numar_bacnote[7] - suma_ceruta / 200;
			suma_ceruta = suma_ceruta % 200; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 200 * numar_bacnote[7];
			numar_bacnote[7] = 0;
		}

		if (suma_ceruta / 100 <= numar_bacnote[6]) {
			numar_bacnote[6] = numar_bacnote[6] - suma_ceruta / 100;
			suma_ceruta = suma_ceruta % 100; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 100 * numar_bacnote[6];
			numar_bacnote[6] = 0;
		}

		if (suma_ceruta / 50 <= numar_bacnote[5]) {
			numar_bacnote[5] = numar_bacnote[5] - suma_ceruta / 50;
			suma_ceruta = suma_ceruta % 50; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 50 * numar_bacnote[5];
			numar_bacnote[5] = 0;
		}

		if (suma_ceruta / 20 <= numar_bacnote[4]) {
			numar_bacnote[4] = numar_bacnote[4] - suma_ceruta / 20;
			suma_ceruta = suma_ceruta % 20; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 20 * numar_bacnote[4];
			numar_bacnote[4] = 0;
		}

		if (suma_ceruta / 10 <= numar_bacnote[3]) {
			numar_bacnote[3] = numar_bacnote[3] - suma_ceruta / 10;
			suma_ceruta = suma_ceruta % 10; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 10 * numar_bacnote[3];
			numar_bacnote[3] = 0;
		}

		if (suma_ceruta / 5 <= numar_bacnote[2]) {
			numar_bacnote[2] = numar_bacnote[2] - suma_ceruta / 5;
			suma_ceruta = suma_ceruta % 5; // daca sunt mai  baconte de de i de cat suma_ceruta
		}
		else {
			suma_ceruta = suma_ceruta - 5 * numar_bacnote[2];
			numar_bacnote[2] = 0;
		}

		if (suma_ceruta <= numar_bacnote[1])
			numar_bacnote[1] = numar_bacnote[1] - suma_ceruta;
		suma_ceruta = suma_ceruta % 10; // daca sunt mai  baconte de de i de cat suma_ceruta



		if (suma_ceruta) {          //daca mai trebuie baconte retrase programul afiseaza si se opreste
			fprintf(g, "NU");
			fclose(f);
			fclose(g);
		}

	}
	fprintf(g, "DA");
	fclose(f);
	fclose(g);


}
int main() {
	retrage_bani();
	return 0;
}