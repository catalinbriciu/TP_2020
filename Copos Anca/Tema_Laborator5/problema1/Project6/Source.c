#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int st[50], vf = 0;
void push(int car)
{
	st[vf++] = car;
}
int pop()
{
	vf--;
	return st[vf];
}
void afisare()
{
	int i;
	for ( i = 0; i < vf; i++)
		printf("%d  ", st[i]);
	printf("\n");
}
void stergere()
{
	while (vf > 0)
		pop();
}
void suma()
{
	int s = 0;
	while (vf > 0)
	{
		s=s+ pop();
	}
	printf("suma elem este: %d\n", s);
}
int main()
{
	char car[10];
	int nr;
	while (1) 
	{
		printf("elem nr %d : ", vf + 1);
		scanf("%s", car);
		if (strcmp(car, ",") == 0)
		{
			pop();
			printf("ult intrare stearsa \n");
			afisare();
		}
		else if (strcmp(car, ".") == 0) 
		{
			stergere();
			printf("stiva a fost stearsa \n");
		}
		else if (strcmp(car, "+") == 0)
		{
			suma();
			break;
		}
		else
		{
			//nr = (int)(car - '0');		?? am citit cv pe net, dar nu merge :(
			//push(nr);						??
			afisare();
		}
	}
	system("pause");
	return 0;
}