/*Sa se masoare performantele (ca timp de executie) a algoritmilor de cautare binara si cautare liniara pentru urmatoarele intrari:
a) sa se genereze un sir de date in ordine crescatoare de lungime 20000 de numere si care sa fie generate ca multipli de
2.
b) Pentru sirul generat la punctul a) ---> sa se caute numarul de pe pozitia 4 si sa se afiseze timpul de procesare pentru cautarea binara si liniara
c) Pentru sirul generat la punctul a) ---> sa se caute numarul de pe pozitia 19935 si sa se afiseze timpul de procesare pentru cautarea binara si cautarea liniara.
d) Sa se rezolve a),b), c) pentru numere generate descrescator.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int v[20000], i, poz;

//int sir()
//{
//	srand(NULL); // functie pt numar random
//	printf("Cate elemente doriti: ");
//	int nr_elem;
//	scanf("%d", &nr_elem);
//	int* vec = (int*)malloc(nr_elem * sizeof(int));
//	int aux;
//	for (int i = 0; i < nr_elem; i++)
//	{
//		do
//		{
//			aux = rand();
//		} while (aux % 2 == 1);
//		vec[i] = aux;
//	}
//	for (int i = 0; i < nr_elem - 1; i++)
//	{
//		for (int j = i + 1; j < nr_elem; j++)
//		{
//			if (vec[i] > vec[j])
//			{
//				aux = vec[i];
//				vec[i] = vec[j];
//				vec[j] = aux;
//			}
//		}
//	}
//	for (int i = 0; i < nr_elem; i++)
//	{
//		printf("%d ", vec[i]);
//	}
//	free(vec);
//}

void sir()
{
	v[0] = 2;
	for (i = 1; i < 20000; i++)
		v[i] = v[i - 1] + 2;
}

void cautare_liniara()
{
	for (i = 0; i <= 20000; i++)
		if (i == poz)
			printf("Numarul de pe pozitia %d fost gasit\n", poz);
}

void afisare()
{
	for (i = 0; i < 20000; i++)
		printf("%d ", v[i]);
}

int main()
{
	printf("Pozitia:");
	scanf("%d", &poz);
	sir();
	cautare_liniara();
	afisare();
	system("pause");
	return 0;
}