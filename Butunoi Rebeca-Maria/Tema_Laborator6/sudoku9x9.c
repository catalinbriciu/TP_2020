#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<tchar.h>
#include<SDKDDKVer.h>
#define SUDOKU_MAX_LINES 9u
#define SUDOKU_MAX_COLUMNS 9u
#define TRUE 1u
#define FALSE 0u
//types defintion
typedef unsigned char boolean;
//global variables section;
unsigned char SolutionArray[SUDOKU_MAX_LINES][SUDOKU_MAX_COLUMNS] = { 0 };
unsigned char n = 0u;
//private functions prototypes ; type can be changed after the type of the problem
boolean Backtracking(int level);
boolean  IsValid(int line, int column, int level);
boolean  IsSolution(int level);
int GetNextElement(int* line, int* column);
void PrintSolution(int level);
boolean IsSudokuFilled(void);

boolean IsValid(int line, int column, int level) {
	int local_line = 0, local_column = 0;
	int box_line = 0;
	int box_column = 0;
	int mapOfNumbers[9] = { 0 };
	//check if the same element is not found on line or on column
	boolean isValid = TRUE;
	//let's verify the column
	for (local_column = 0; ((local_column < SUDOKU_MAX_COLUMNS) && (isValid == TRUE)); local_column++) {
		if (SolutionArray[line][local_column] == level) {
			isValid = FALSE;
		}
	}
	//let's verify the line
	for (local_line = 0; ((local_line < SUDOKU_MAX_LINES) && (isValid == TRUE)); local_line++) {
		if (SolutionArray[local_line][column] == level) {
			isValid = FALSE;
		}
	}
	if (isValid == TRUE) {
		//let's verify also the box on which is atteinded
		box_line = line-line%  3;
		box_column = column-column% 3;
		for (local_line = box_line; local_line < box_line + 3; local_line++) {
			for (local_column = box_column; local_column < box_column + 3; local_column++) {
				if (SolutionArray[local_line][local_column] > 0) {
					mapOfNumbers[SolutionArray[local_line][local_column] - 1u]++;
				}
			}
		}
		if (mapOfNumbers[level - 1] > 1u) {
			isValid = FALSE;
		}
	}
	return isValid;
}

boolean IsBoxedSolution(int column, int line) {
	int mapOfNumbers[9] = { 0 };
	int local_column = column-column%3;
	int local_line = line-line%3;
	int counter = 0;
	//search for one;
	for (local_line = line; local_line < line + 3; local_line++) {
		for (local_column = column; local_column < column + 3; local_column++) {
			mapOfNumbers[SolutionArray[local_line][local_column] - 1u]++;
		}
	}
	//the frequency table was built; let's check it; all numbers needs to appear only once
	for (counter = 0; counter < 9; counter++) {
		if (mapOfNumbers[counter] != 1u) {
			return FALSE;
		}
	}
	return TRUE;
}

boolean IsSolution(int level) {
	boolean isSol = TRUE;
	int line, column = 0;
	//is solutino if there is not an empty place into the solution array
	for (line = 0; ((line < SUDOKU_MAX_LINES) && (isSol == TRUE)); line++) {
		for (column = 0; ((column < SUDOKU_MAX_COLUMNS) && (isSol == TRUE)); column++)
		{
			if (SolutionArray[line][column] == 0) {
				isSol = FALSE;
			}
		}
	}
	//additional check needs to be done to see if all numbers are present into the 3x3 box
	//current problem is only needs to check from 0 to 0
	if (isSol == TRUE) {
		for (line = 0; ((line < SUDOKU_MAX_LINES) && (isSol == TRUE)); line += 3) {
			for (column = 0; ((column < SUDOKU_MAX_COLUMNS) && (isSol == TRUE)); column += 3)
			{
				isSol = IsBoxedSolution(line, column);
				if (isSol == FALSE) {
					return isSol;
				}
			}
		}
	}
	return isSol;
}

void PrintSolution(int level) {
	int line, column = 0;
	printf("----------------------------\n");
	for (line = 0; line < SUDOKU_MAX_LINES; line++) {
		for (column = 0; column < SUDOKU_MAX_COLUMNS; column++)
		{
			printf(" %d ", SolutionArray[line][column]);
		}
		printf("\n");
	}
	printf("----------------------------\n");
}

int GetNextElement(int* line, int* column) {
	int local_line, local_column;
	*line = 0;
	*column = 0;
	boolean SudokuEmptyPosFound = FALSE;
	for (local_line = 0; ((local_line < SUDOKU_MAX_LINES) && (SudokuEmptyPosFound == FALSE)); local_line++) {
		for (local_column = 0; ((local_column < SUDOKU_MAX_COLUMNS) && (SudokuEmptyPosFound == FALSE)); local_column++)
		{
			if (SolutionArray[local_line][local_column] == 0) {
				SudokuEmptyPosFound = TRUE;
				break;
			}
		}
		if (SudokuEmptyPosFound == TRUE) {
			break;
		}
	}
	if (SudokuEmptyPosFound == TRUE) {
		*line = local_line;
		*column = local_column;
	}
	return 0;
}

boolean IsSudokuFilled(void) {
	int line, column = 0;
	boolean SudokuIsFilled = TRUE;
	for (line = 0; (line < SUDOKU_MAX_LINES && (SudokuIsFilled == TRUE)); line++) {
		for (column = 0; (column < SUDOKU_MAX_COLUMNS && (SudokuIsFilled == TRUE)); column++)
		{
			if (SolutionArray[line][column] == 0) {
				SudokuIsFilled = FALSE;
			}
		}
	}
	return SudokuIsFilled;
}

boolean Backtracking(int level) {
	int index;
	boolean SudokuIsFilled;
	//check if we are finding an empty cell in our matrix
	SudokuIsFilled = IsSudokuFilled();
	if (SudokuIsFilled == TRUE) {
		//end of game; we can exit the algorithm;
		return TRUE;
	}
	else {
		//let's fill it
		for (index = 1; index <= n; index++) {
			int column = 0, line = 0;
			//find the first element which is not filled
			GetNextElement(&line, &column);
			//check if the number is valid
			if (TRUE == IsValid(line, column, index)) {
				//let's assign them on the line and column the number;
				SolutionArray[line][column] = index;
				//number seems to be valid; check if we did not reached the final solution
				if (TRUE == IsSolution(level)) {
					//yey; it seems that we had reached the final soluition
					PrintSolution(level + 1);
					return TRUE;
				}
				else {
					//arghh, let's go one level up
					Backtracking(level + 1);
					//let's unassgined the solution
					SolutionArray[line][column] = 0;
				}
			}
			else {
				//the number seems not to be valid
			}
		}
		return FALSE;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	n = 9;
	SolutionArray[0][0] = 1;
	SolutionArray[0][1] = 3;
	SolutionArray[2][2] = 5;
	//9x9 sudoku
	SolutionArray[0][0] = 5;
	SolutionArray[0][1] = 3;
	SolutionArray[0][4] = 7;
	SolutionArray[1][0] = 6;
	SolutionArray[1][3] = 1;
	SolutionArray[1][4] = 9;
	SolutionArray[1][5] = 5;
	SolutionArray[2][1] = 9;
	SolutionArray[2][2] = 8;
	SolutionArray[2][7] = 6;
	SolutionArray[3][0] = 8;
	SolutionArray[4][0] = 4;
	SolutionArray[5][0] = 7;
	SolutionArray[8][8] = 1;
	PrintSolution(0);
	Backtracking(0);
	PrintSolution(0);
	getchar();
	return 0;
}