#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
FILE *fin;
int stiva[50];
int varf = 0;
void push(int x)
{
	stiva[++varf] = x;
}
void afiseaza_stiva()
{
	for (int i = 1;i <= varf;i++)
	{
		printf("%d ", stiva[i]);
	}
	printf("\n");
}
int convertArrayToNumber(unsigned char * string, unsigned char length) {
	int counter = 0;
	int MyNumber = 0;
	for (counter = 0; counter < length; counter++) {
		MyNumber = MyNumber * 10 + (string[counter] - 48u);
	}
	return MyNumber;
}
int main()
{
	bool entireLine = true;
	bool endOfFile = false;
	fin = fopen("in.txt", "rt");
	unsigned char a[1000];
	unsigned char tempCharArray[100];
	int i = 0;
	int length = 0;
	while (entireLine == true && (false == endOfFile)) {
		unsigned char temporary;
		fscanf(fin, "%c", &temporary);
		if (temporary == '\n') {
			entireLine = false;
			if (length > 0) a[i] = convertArrayToNumber(&tempCharArray[0], length);
			length = 0;
			i++;
		}
		else if (temporary == '\r')
		{
			endOfFile = true;
			if (length > 0) a[i] = convertArrayToNumber(&tempCharArray[0], length);
			length = 0;
			i++;
		}
		else if (temporary == 32 /*character empty ''*/) {
			if (length > 0) a[i] = convertArrayToNumber(&tempCharArray[0], length);
			length = 0;
			i++;
		}
		else { tempCharArray[length] = temporary;  length++; }
	}
	fclose(fin);
	for (int count = 0;count < i;count++) {
		push(a[count]);
	}
	afiseaza_stiva();
	system("pause");
	return 0;
}