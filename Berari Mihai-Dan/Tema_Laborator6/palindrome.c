////2. Sa se genereze toate numerele palindrome de lungime n
//nu imi afiseaza solutia
#include<stdio.h>
#include<stdlib.h>

int i, vf, n, x[100], sol = 0; m;
char isSucc, isVal = 0;
void Init(int vf) {
	x[vf] = 0;

}
int Next(int vf) {
	if (x[vf] < n) {
		x[vf]++;
		return 1;
	}
	else
		return 0;
}

int Valid(int vf) {
	int reversed = 0;
	int nr = vf;
	for (i = 1; i <= m; i++) {
		vf = x[i];
		while (nr != 0)
		{
			reversed = reversed * 10 + (nr % 10);
			nr = nr / 10;
		}

		if (x[i] == reversed)

			return 1;
	}

	return 0;
}
int Solution(vf) {
	return (vf == m);
}
void Print() {
	printf("%d : ", ++sol);
	for (i = 1; i <= m; i++)
		printf("%d ", x[i]);
	printf("\n");
}
void Back() {
	vf = 1; Init(vf);
	while (vf > 0) {
		isSucc = 0; isVal = 0;
		if (vf <= m)
			do {
				isSucc = Next(vf);
				if (isSucc) isVal = Valid(vf);
			} while (isSucc && !isVal);
			if (isSucc)
				if (Solution(vf))
					Print();
				else {
					vf++;
					Init(vf);
				}
			else
				vf--;
	}
}
int main() {
	printf("n= ");
	scanf("%d", &n);
	Back();
	return 0;
	system("pause");
	return 0;

}

