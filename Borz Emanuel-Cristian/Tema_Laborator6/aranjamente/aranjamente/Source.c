#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int i, varf, n,cate, indice, v[100];
char isSucc, isVal = 0;

int Succesor(int varf) {
	if (v[varf] < n) { // se poate creşte valoarea din vârf
		v[varf]++;
		return 1;
	}
	else
		return 0;
}
int Valid(varf) {
	for (i = 1; i < varf; i++) // verifică unicitatea elementului/ daca nu se repeta
		if (v[i] == v[varf]) return 0;
	return 1;
}
int Solutie(varf) {
	return (varf == cate);
}
void Afisare() {
	printf("%d : ", ++indice);
	for (i = 1; i <= cate; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void aranjamente() {
	varf = 1; v[varf] = 0;
	while (varf > 0) { // stiva nu e vidă
		isSucc = 0; isVal = 0;
		if (varf <= n)
			do {
				isSucc = Succesor(varf);
				if (isSucc) isVal = Valid(varf);
			} while (isSucc && !isVal); // succesor nevalid
			if (isSucc) //succesor valid
				if (Solutie(varf)) // este solutie?
					Afisare(); // afişează soluţia daca da
				else { // Nu e sol -> creste varful stivei
					varf++; v[varf] = 0;
				}
			else
				varf--; // -> coboară o poziţie în stivă
	}
}

int main()
{
	n = 4; cate = 3;
	aranjamente();
	return 0;

}