#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int stiva[50];
int varf = 0;
void push(int val){
	stiva[++varf] = val;
	return 1;
}
int pop(){
	return stiva[varf--];
	return 1;
}
void afiseaza_st(){
	for (int i = 1; i <= varf; i++)	{
		printf("%d ", stiva[i]);
	}
	printf("\n");
}
int main()
{
	int val;
	printf("Introduceti valoarea: ");
	scanf("%d", &val);
	push(val);
	afiseaza_st();
	while (stiva[1] < 12)
	{
		if (stiva[varf] >= 12 && varf > 0) {
			stiva[varf - 1] = stiva[varf] - 1;
			pop();
		}
		else
			push(stiva[varf] + 2);
		afiseaza_st();
	}
	printf("Valoarea functiei Manna Pnueli este egala cu : %d .\n", val, stiva[varf] - 1);
	system("pause");
	return 0;
}