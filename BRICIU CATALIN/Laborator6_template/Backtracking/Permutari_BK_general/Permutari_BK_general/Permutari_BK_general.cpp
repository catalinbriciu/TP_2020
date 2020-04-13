// Permutari_BK_general.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/* forma generala a unui algorithm cu BK

	void BK(int k) // k fiind pozitia din vectorul solutiei - k (solutia partiala)
	{	int i;
		for (i = 0; i < nr_elemente_domeniul solutiei; i++) //parcurge elementele multimii Sk
		{ 
			v[k]= getNextElement(i); //selectează un element din multime
			if (validare(k)==1) //solutia partiala obtinuta este valid prin prisma regulilor (e.g doua numere consecutive sa nu fie acelasi( 
				{ 
					if (solutie(k)==1) { //verifică dacă am ajuns la o solutie (e.g. numerele consecutive sa nu fie identice)
						afisare(k); //afisam vector v - al solutiilor partial pentru ca se pare ca solutia partiala este si finala
					} else {
						BK(k+1); //solutia partiala este valida, dar nu finala (e.g doar 5 numere consecutive diferite, in loc de 6)
					}
				}
		} //dacă nu mai exista nici un element neselectat din multimea domeniuilui multimii
	} //se închide nivelul de stiva si astfel se revine pe pozitia k-1 a vectorului
//executia functiei se incheie, după ce s-au inchis toate nivelurile stivei, inseamna ca in vectorul v nu mai poate fi selectat nici un elemente din multimile Sk
*/

//macrodefinitions section
#define SOLUTION_ARRAY_MAX_SIZE 10u
#define TRUE 1u
#define FALSE 0u
#define _no_PERMUTARI
#define COMBINARI 
//types defintion
typedef unsigned char boolean;
//global variables section;
unsigned char SolutionArray[SOLUTION_ARRAY_MAX_SIZE] = { 0 };
unsigned char n = 0u;
#ifndef PERMUTARI
unsigned char k = 0u;
#endif
//private functions prototypes ; type can be changed after the type of the problem
void Backtracking(int level);
boolean  IsValid(int level);
boolean  IsSolution(int level);
int  GetNextElement(int level);
void PrintSolution(int level);

boolean IsValid(int level) {
	boolean valid = TRUE;
	unsigned char ndx = 0;
	for (ndx = 0; ((ndx < level) && (valid == TRUE)); ndx++) {
		if (SolutionArray[ndx] == SolutionArray[level]) {
			valid = FALSE;
		}
	}
	return valid;
}

#ifdef PERMUTARI
/*solution permutari*/
boolean IsSolution(int level) {
	boolean isSol = FALSE;
	if (level == (n - 1)) {
		isSol = TRUE;
	}
	return isSol;
}
#else
/*solution aranjamente*/
boolean IsSolution(int level) {
	boolean isSol = FALSE;
	if (level == (k - 1)) {
		isSol = TRUE;
	}
	return isSol;
}
#endif

void PrintSolution(int level) {
	unsigned char ndx;
	printf("\n");
	printf("solution: ");
	for (ndx = 0; ndx < level; ndx++) {
		const unsigned char noToPrint = SolutionArray[ndx] + 1u;
		printf(" %d ", noToPrint);
	}
	printf("\n");
}

int GetNextElement(int level) {
	return level;
}

void Backtracking(int level) {
	int index;
	for (index = 0; index < n; index++) {
		SolutionArray[level] = GetNextElement(index);
		//check if the number is valid
		if (TRUE == IsValid(level)) {
			//number seems to be valid; check if we did not reached the final solution
			if (TRUE == IsSolution(level)) {
				//yey; it seems that we had reached the final soluition
				PrintSolution(level + 1);
			}
			else {
				//arghh, let's go one level up
				Backtracking(level + 1);
			}
		}
		else {
			//the number seems not to be valid
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//simulate the behavior for n = 3;
#ifndef PERMUTARI
	k = 2u;
#endif
	n = 3;
	Backtracking(0);
	getchar();
	return 0;
}

