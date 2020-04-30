#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int vf, n, v[MAX], sol=0;

int Solution(int vf){
	if (vf == n)
		return 1;
	return 0;
}

int Valid(int vf){
	int i;
	for (i = 1; i <= vf - 1; i++)
		if ((v[i] == v[vf]) || (abs(v[vf] - v[i]) == (vf - i)))
			return 0;
	return 1;
}

void Print(){
	int i, j;
	printf("\nSolutia:%d\n", sol++);
	for (i = 1; i <= vf; i++){
		for (j = 1; j <= vf; j++)
			if (v[i] == j)
				printf("R ");
			else printf("- ");
		printf("\n");
	}
}
void Back(int vf){
	int i;
	for (i = 1; i <= n; i++){
		v[vf] = i;
		if (Valid(vf) == 1){
			if (Solution(vf) == 1) 
				Print(); 
			else
				Back(vf + 1); 
		}
	}
}
int main(){
	printf("Dimensiune tabla="); scanf("%d", &n);
	Back(1);
	system("pause");
	return 0;
}