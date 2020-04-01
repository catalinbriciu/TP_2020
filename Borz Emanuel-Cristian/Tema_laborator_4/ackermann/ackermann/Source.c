#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)
struct Stiva_Ackermann {
	int stiva_1st[50], stiva_2nd[50];
}ack;
int varf_1st = 0, varf_2nd = 0;

void push_1st(int val);
void push_2nd(int val);
void pop_1st();
void pop_2nd();
void afisare_stiva();


int main()
{
	int x, y;
	printf("x= ");
	scanf("%d", &x);
	printf("y= ");
	scanf("%d", &y);
	push_1st(x);
	push_2nd(y);
	afisare_stiva();
	while (ack.stiva_1st[1] > 0) {
		if (ack.stiva_1st[varf_1st] != 0 && ack.stiva_2nd[varf_2nd] != 0) {
			push_1st(ack.stiva_1st[varf_1st]);
			push_2nd(ack.stiva_2nd[varf_2nd] - 1);
		}
		else if (ack.stiva_2nd[varf_2nd] == 0) {
			ack.stiva_1st[varf_1st] = ack.stiva_1st[varf_1st] - 1;
			ack.stiva_2nd[varf_2nd] = 1;
		}
		else if (ack.stiva_1st[varf_1st] == 0) {
			ack.stiva_1st[varf_1st - 1] = ack.stiva_1st[varf_1st - 1] - 1;
			ack.stiva_2nd[varf_2nd - 1] = ack.stiva_2nd[varf_2nd] + 1;
			pop_1st();
			pop_2nd();
		}
		afisare_stiva();
	}
	printf("Functia Ackermann f(%d,%d) are valoarea: %d .\n", x, y, ack.stiva_2nd[varf_2nd] + 1);
	system("pause");
	return 0;
}


void push_1st(int val)
{
	ack.stiva_1st[++varf_1st] = val;
}
void push_2nd(int val)
{
	ack.stiva_2nd[++varf_2nd] = val;
}
void pop_1st()
{
	ack.stiva_1st[varf_1st--];
}
void pop_2nd()
{
	ack.stiva_2nd[varf_2nd--];
}
void afisare_stiva()
{
	int i;
	printf("\n\n");
	for (i = 1; i <= varf_1st; i++)
		printf("%d ", ack.stiva_1st[i]);
	printf("\n");
	for (i = 1; i <= varf_2nd; i++)
		printf("%d ", ack.stiva_2nd[i]);
	printf("\n\n");
}