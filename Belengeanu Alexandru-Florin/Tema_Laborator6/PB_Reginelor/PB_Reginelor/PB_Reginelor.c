#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#define SOLUTION_ARRAY_MAX_SIZE 10u
#define TRUE 1u
#define FALSE 0u 
//types defintion
typedef unsigned char boolean;
//global variables section;
unsigned char SolutionArray[SOLUTION_ARRAY_MAX_SIZE] = { 0 };
unsigned char n = 0u;
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
		if (SolutionArray[ndx] == SolutionArray[level] || abs(SolutionArray[ndx] - SolutionArray[level]) == abs(ndx - level)) {
			valid = FALSE;
		}
	}
	return valid;
}

boolean IsSolution(int level) {
	boolean isSol = FALSE;
	if (level == (n - 1)) {
		isSol = TRUE;
	}
	return isSol;
}

void PrintSolution(int level) {
	unsigned char ndx;
	unsigned char ndx2;
	unsigned char noToPrint = 'R';
	printf("\n");
	printf("solution: ");
	for (ndx = 0; ndx < level; ndx++) {
		printf("\n");
		for (ndx2 = 0; ndx2 < level;ndx2++) {
			if (SolutionArray[ndx] == ndx2) {
				const unsigned char noToPrint = SolutionArray[ndx] + 1u;
				printf(" %hhd ", noToPrint);
			}
			else
				printf(" * ");
		}
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
	//simulate the behavior for n = 4;
	printf("n= ");
	scanf("%d", &n);
	Backtracking(0);
	getchar();
	system("pause");
	return 0;
}