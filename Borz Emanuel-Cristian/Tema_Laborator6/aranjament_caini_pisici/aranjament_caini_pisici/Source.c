#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
int stiva[100], caine, pisica, nr = 0;

int verifica(int varf){
	int c = 0, p = 0, i;
	for (i = 1; i <= varf; i++)
		if (stiva[i]!= 0) p++;
		else
			c++;
	if (c > caine || p > pisica ) return 0;
	if (varf >= 3) if (stiva[varf] == 0 && stiva[varf - 2] == 0 && stiva[varf - 1] == 1) return 0;
	return 1;
}
void afisare(){
	for (int i = 1; i <= pisica + caine; i++)
		if (stiva[i] != 1)
			printf(" Dog ");
		else printf(" Cat ");
	printf("\n------------------------------------------------------- \n");
	nr++;
}
void backtracking(int varf) {
	int i;
	for (i = 1; i >= 0; i--) {
		stiva[varf] = i;
		if (verifica(varf))
			if (varf == pisica + caine)
				afisare();
			else
				backtracking(varf + 1);
	}
}
int main(){	printf("Cati caini?: "); scanf("%d", &caine);
	printf("Cate pisici?: "); scanf("%d", &pisica);
	backtracking(1);
	printf("Putem aseza in linie %d caini si %d pisici astfel incat sa nu existe o singura pisica intre 2 caini in %d moduri \n",caine,pisica, nr);
}

