/*Pentru afisarea verticala a unui numar întreg(câte o cifra pe rând) se poate folosi o stiva în care
se vor depune resturile împartirilor repetate la 10.
Scrieti o functie avînd ca argument un numar întreg, care îl afiseaza vertical, folosind o stiva.
void AfisStivaNr(int number) {
}
123
1
2
3
}
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
unsigned char Stiva[MAX];
unsigned char *SP;

void Crează(unsigned char *Stiva, unsigned char *SP){
	unsigned char count;
	*SP = 0;
	for (count = 0; count < MAX; count++)
	{
		Stiva[count] = 0;
	}
}

unsigned char IsStackEmpty(unsigned char* SP)
{
	if ((*(SP)) == 0)
		return 1;
	else
		return 0;
}
unsigned char IsStackFull(unsigned char* SP)
{
	if ((*(SP)) == MAX - 1)
		return 1;
	else
		return 0;
}
void Push(unsigned char *Stiva, unsigned char *SP, unsigned char NewVal)
{
	if (IsStackFull(&SP) != 1)
	{
		Stiva[*SP] = NewVal;
		*SP = *SP + 1;
	}
	else
	{
		printf("Stiva e plină");
	}
}
void Pop(unsigned char *Stiva, unsigned char *SP)
{
	unsigned char ReturnedValue = 0;
	if (IsStackEmpty != 0)
	{
		*SP = *SP - 1;
		ReturnedValue = Stiva[*SP];
		return ReturnedValue;
	}
	else
		return ReturnedValue;

 }
void Afiseaza_Stiva(unsigned int Value)
{
	unsigned int aux;
	while (Value) 
	{
		aux = Value%10;
		Push(&Stiva[0], &SP, aux);
		Value = Value/10;
	}
	while (IsStackEmpty(&SP) != 1)
	{
		Value = Pop(&Stiva[0], &SP);
		printf("%d\n", Value);
	}

}
int main()
{
	unsigned int Val;
	printf("Introduceti numarul: ");
	scanf("%d", &Val);
	printf("Numarul este: \n");
	Crează(&Stiva[0], &SP);
	AfiseazăStiva(Val);
	system("pause");
	return 0;
}

