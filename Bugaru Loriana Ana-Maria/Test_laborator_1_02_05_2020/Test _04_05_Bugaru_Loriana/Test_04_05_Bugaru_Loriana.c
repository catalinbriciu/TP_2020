#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_STIVA 250u

unsigned char Stiva[MAX_STIVA];

unsigned char PointerStiva;

void CreeazaStiva(unsigned char * Stiva, unsigned char * PS)

{

	unsigned char count;

	*PS = 0u;

	for (count = 0; count < MAX_STIVA; count++)

	{

		Stiva[count] = 0x00;

	}


}

unsigned char StivaPlina(unsigned char *PS)

{

	return ((*(PS)) == 0x00u);

}

unsigned char StivaGoala(unsigned char *PS)

{

	return ((*PS) == (MAX_STIVA - 1u));

}

void Push(unsigned char* Stiva, unsigned char * PS, unsigned char ValoareAdaugata)

{

	if (!StivaPlina(&PS))

	{

		Stiva[*PS] = ValoareAdaugata;

		*PS = *PS + 1u;

	}

	else

	{

		/*stiva plina*/

	}

}

unsigned char Pop(unsigned char * Stiva, unsigned char *PS)

{

	unsigned char ValoareReturnata = 0xFF;

	if (!StivaGoala(&PS))

	{

		*PS = *PS - 1u;

		ValoareReturnata = Stiva[*PS];

		return ValoareReturnata;

	}

	else

	{

		return ValoareReturnata;

	}

}

void Punctul_1(unsigned int Numar)
{
	unsigned int Cifra;

	while (Numar)
	{
		Cifra = Numar % 8;
		Push(&Stiva[0], &PointerStiva, Cifra);
		Numar = Numar / 8;

	}
	while (StivaGoala(&PointerStiva) != 1)
	{
		Numar = Pop(&Stiva[0], &PointerStiva);
		printf("%u\n", Numar);
	}

}

int main()
{
	unsigned int Numar;

	printf("Deimpartitul este :");
	scanf("%u", &Numar);
	

	printf("Afisarea numarului sub forma de stiva:\n");

	CreeazaStiva(&Stiva[0], &PointerStiva);
	Punctul_1(Numar);

	_getch();

	system("pause");
	return 0;

}