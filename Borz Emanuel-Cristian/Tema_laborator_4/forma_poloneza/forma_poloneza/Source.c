#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 100

char expresie[MAX], fp[MAX];
int i = 0, lp = 0;
char adunare = '+', inmultire = '*', impartire = '/', scadere = '-';


void TransformareExpresie();
void TransformareFactor();
void TransformareTermen();
void Push();

int main() {
	printf("\nIntroduceti expresia: ");
	scanf("%s", expresie);
	TransformareExpresie();
	printf("\nForma poloneza postfixata a exresiei este: %s", fp);

	getch();
	return 0;
}

void Push(char k) {
	fp[lp] = k;
	lp++;
}

void TransformareFactor() {
	if (expresie[i] == '(') {
		i++;
		TransformareExpresie();
		i++;
	}
	else
	{
		Push(expresie[i++]);
	}
}

void TransformareTermen() {
	TransformareFactor();
	while (i < strlen(expresie) && (expresie[i] == '*' || expresie[i] == '/')) {
		i++;
		TransformareFactor();
		if (expresie[i] == '*') {
			Push(inmultire);
		}
		else {
			Push(impartire);
		}

	}

}

void TransformareExpresie() {
	TransformareTermen();
	while (i < strlen(expresie) && (expresie[i] == '+' || expresie[i] == '-')) {
		i++;
		TransformareTermen();
		if (expresie[i] == '+') {
			Push(adunare);
		}
		else {
			Push(scadere);
		}
	}
}