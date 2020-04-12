
#include<stdio.h>
#include<stdlib.h>

int i, k, n, v[100], sol = 0; cnt = 0, m;
char isS, isV = 0;
void Init(int k) { // k – vârful stivei
	v[k] = 0; //iniþializeazã/reseteazã, valoarea din
	// vârful stivei
}
int Succesor(int k) {
	if (v[k] < n) { // se poate creºte valoarea din vârf
		v[k]++; // se incrementeazã valoarea din vârf
		return 1; // funcþia a avut success
	}
	else // nu se poate creºte valoarea din vârf
		return 0;
}

int Valid(int k) {
	int oglindit = 0;
	int copie, cifra;
	for (i = 1; i <= m; i++) {

		copie = v[i];
		while (copie != 0)
		{
			cifra = copie % 10;
			copie = copie / 10;
			oglindit = oglindit * 10 + cifra;
		}

		if (v[i] == oglindit)

			return 1;
	}
	
	return 0;
}
int Solution(k) {
	return (k == m);
}
void Print() {
	printf("%d : ", ++sol);
	for (i = 1; i <= m; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void Back() {
	k = 1; Init(k);
	while (k > 0) { // cât timp stiva nu e vidã
		isS = 0; isV = 0;
		if (k <= m) // nu are sens depãºirea nivelului m în stivã
			do { // repetã cât timp...
				isS = Succesor(k);
				if (isS) isV = Valid(k);
			} while (isS && !isV); // ...existã succesor dar nu este valid
			if (isS) //este succesor si este valid
				if (Solution(k)) // verificã candidatul la soluþie
					Print(); // afiºeazã soluþia
				else { // dacã nu este soluþie
					k++;
					Init(k); // creºte vârful stivei ºi iniþializeazã
				}
			else // nu existã succesor pt. valoarea curentã din stivã
				k--; // -> se coboarã o poziþie în stivã
	}
}
int main() {
	int n = 44;
	Back();
	return 0;
	system("pause");
	return 0;

}