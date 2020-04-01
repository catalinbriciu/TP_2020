#include <stdlib.h>
#include <stdio.h>
struct StiveAckerman {
	int stiva_x[50], stiva_y[50];
}ack;
int varf_x = 0, varf_y = 0;
void push_x(int valoare)
{
	ack.stiva_x[++varf_x] = valoare;
}
void push_y(int valoare)
{
	ack.stiva_y[++varf_y] = valoare;
}
void pop_x()
{
	ack.stiva_x[varf_x--];
}
void pop_y()
{
	ack.stiva_y[varf_y--];
}
void afisare_stive()
{
	printf("\n\n");
	for (int i = 1; i <= varf_x; i++)
		printf("%d ", ack.stiva_x[i]);
	printf("\n");
	for (int i = 1; i <= varf_y; i++)
		printf("%d ", ack.stiva_y[i]);
	printf("\n\n");
}
int main()
{
	int x, y;
	printf("x= ");
	scanf("%d", &x);
	printf("y= ");
	scanf("%d", &y);
	push_x(x);
	push_y(y);
	afisare_stive();
	while (ack.stiva_x[1] > 0) {
		if (ack.stiva_x[varf_x] != 0 && ack.stiva_y[varf_y] != 0) {
			push_x(ack.stiva_x[varf_x]);
			push_y(ack.stiva_y[varf_y] - 1);
		}
		else if (ack.stiva_y[varf_y] == 0) {
			ack.stiva_x[varf_x] = ack.stiva_x[varf_x] - 1;
			ack.stiva_y[varf_y] = 1;
		}
		else if (ack.stiva_x[varf_x] == 0) {
			ack.stiva_x[varf_x - 1] = ack.stiva_x[varf_x - 1] - 1;
			ack.stiva_y[varf_y - 1] = ack.stiva_y[varf_y] + 1;
			pop_x();
			pop_y();
		}
		afisare_stive();
	}
	printf("Valoarea functiei Ackerman f(%d,%d) este egala cu : %d .\n", x, y, ack.stiva_y[varf_y] + 1);
	system("pause");
	return 0;
}