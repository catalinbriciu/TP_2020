#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#pragma warning(disable:4996)
int i, varf, n, v[MAX], sol = 0;;
char isS, isV = 0;

void Init(int varf) {

	v[varf] = 0;

}

int Succesor(varf) {

	if (v[varf] < n) {
		v[varf]++;
		return 1;
	}
	else
		return 0;

}

int Valid(varf) {

	for (i = 1; i < varf; i++)
		if ((abs(v[varf] - v[i]) == abs(varf - i)) || (v[i] == v[varf])) return  0;
	return 1;
}

int Solutie(varf) {

	return (varf == n);

}

void Afisare() {

	printf("%d:\n", sol++);
	for (int i = 1; i <= varf; i++) {
		for (int j = 1; j <= varf; j++)
			if (v[i] == j)
				printf("Q ");
			else printf("# ");
		printf("\n");
	}

}

void Queens() {

	varf = 1; Init(varf);

	while (varf > 0) {
		isS = 0; isV = 0;
		if (varf <= n)
			do {
				isS = Succesor(varf); // cauta succesor
				if (isS != 0) isV = Valid(varf);
			} while (isS != 0 && isV == 0);

			if (isS != 0 && isV != 0) //este succesor si este valid
				if (Solutie(varf) != 0)
					Afisare();
				else {
					varf++;
					Init(varf);
				}
			else  //nu am succesor -> cobor o pozitie in stiva
				varf--;
	}
}

int main()
{

	printf("Dimensiune tabla="); scanf("%d", &n);
	Queens();
	return 0;
}
