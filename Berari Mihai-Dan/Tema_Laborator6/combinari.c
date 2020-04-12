#include<stdio.h>
#include<stdlib.h>
int i, vf, n, c, indice, v[100];
char isSucc, isVal = 0;

int Next(int vf) {
	if (v[vf] < n) { 
		v[vf]++;
		return 1;
	}
	else
		return 0;
}
int Valid(vf) {
	for (i = 1; i < vf; i++)
		if (v[i] >= v[vf]) return 0;
	return 1;
}
int Solution(vf) {
	return (vf == c);
}
void Print() {
	printf("%d : ", ++indice);
	for (i = 1; i <= c; i++)
		printf("%d ", v[i]);
	printf("\n");
}
void Back() {
	vf = 1; v[vf] = 0;
	while (vf > 0) { 
		isSucc = 0; isVal = 0;
		if (vf <= n)
			do {
				isSucc = Next(vf);
				if (isSucc) isVal = Valid(vf);
			} while (isSucc && !isVal); 
			if (isSucc) 
				if (Solution(vf)) 
					Print();
				else { 
					vf++; v[vf] = 0;
				}
			else
				vf--; 
	}
}

int main()
{
	printf("n="); scanf("%d", &n);
	printf("c="); scanf("%d", &c);
	Back();
	system("pause");
	return 0;

}