//#include <stdlib.h>
//#include <stdio.h>
//struct Stiva_Ackerman {
//	int stiva_x[50], stiva_y[50];
//}Ackerman;
//int varf_x = 0, varf_y = 0;
//void push_x(int val)
//{
//	Ackerman.stiva_x[++varf_x] = val;
//}
//void push_y(int val)
//{
//	Ackerman.stiva_y[++varf_y] = val;
//}
//void pop_x()
//{
//	Ackerman.stiva_x[varf_x--];
//}
//void pop_y()
//{
//	Ackerman.stiva_y[varf_y--];
//}
//void afisare_stiva()
//{
//	int i;
//	printf("\n\n");
//	for (i = 1; i <= varf_x; i++)
//		printf("%d ", Ackerman.stiva_x[i]);
//	printf("\n");
//	for (i = 1; i <= varf_y; i++)
//		printf("%d ", Ackerman.stiva_y[i]);
//	printf("\n\n");
//}
//int main()
//{
//	int x, y;
//	printf("x= ");
//	scanf("%d", &x);
//	printf("y= ");
//	scanf("%d", &y);
//	push_x(x);
//	push_y(y);
//	afisare_stiva();
//	while (Ackerman.stiva_x[1] > 0) {
//		if (Ackerman.stiva_x[varf_x] != 0 && Ackerman.stiva_y[varf_y] != 0) {
//			push_x(Ackerman.stiva_x[varf_x]);
//			push_y(Ackerman.stiva_y[varf_y] - 1);
//		}
//		else if (Ackerman.stiva_y[varf_y] == 0) {
//			Ackerman.stiva_x[varf_x] = Ackerman.stiva_x[varf_x] - 1;
//			Ackerman.stiva_y[varf_y] = 1;
//		}
//		else if (Ackerman.stiva_x[varf_x] == 0) {
//			Ackerman.stiva_x[varf_x - 1] = Ackerman.stiva_x[varf_x - 1] - 1;
//			Ackerman.stiva_y[varf_y - 1] = Ackerman.stiva_y[varf_y] + 1;
//			pop_x();
//			pop_y();
//		}
//		afisare_stiva();
//	}
//	printf("valoarea functiei Ackermanerman f(%d,%d) este egala cu : %d .\n", x, y, Ackerman.stiva_y[varf_y] + 1);
//	system("pause");
//	return 0;
//}