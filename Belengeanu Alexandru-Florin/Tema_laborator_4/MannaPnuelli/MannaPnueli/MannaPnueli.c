/**
f(2) = f(f(4)) = f(f(f(6))) = f(f(f(f(8)))) = f(f(f(f(f(10))))) = f(f(f(f(f(f(12)))))) = f(f(f(f(f(11))))) = f(f(f(f(f(f(13)))))) =
 = f(f(f(f(f(12))))) = f(f(f(f(11)))) = f(f(f(f(f(13))))) = f(f(f(f(12)))) = f(f(f(11))) = f(f(f(f(13)))) = f(f(f(12))) = f(f(11)) =
 = f(f(f(13))) = f(f(12)) = f(11) = f(f(13)) = f(12) = 11 .
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int stiva[50];
int varf = 0;
void push(int x)
{
	stiva[++varf] = x;
}
int pop()
{
	return stiva[varf--];
}
void afiseaza_stiva()
{
	for (int i = 1;i <= varf;i++)
	{
		printf("%d ", stiva[i]);
	}
	printf("\n");
}
int main() 
{
	int x;
	printf("Introduceti valoarea variabilei x : ");
	scanf("%d", &x);
	push(x);
	//afiseaza_stiva();
	while (stiva[1] < 12)
	{
		if (stiva[varf] >= 12 && varf > 0) {
			stiva[varf - 1] = stiva[varf] - 1;
			pop();
		}
		else
			push(stiva[varf] + 2);
		//afiseaza_stiva();
	}
	printf("Valoarea functiei Manna Pnueli f(%d) este egala cu : %d .\n", x, stiva[varf]-1);
	system("pause");
	return 0;
}