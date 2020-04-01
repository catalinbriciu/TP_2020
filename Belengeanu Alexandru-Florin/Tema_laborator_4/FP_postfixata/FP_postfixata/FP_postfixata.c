#include<stdio.h>
#include<stdlib.h>    
#include<ctype.h>     
#include<string.h>
unsigned char fp[50], stiva[50];
int varf = -1;
void push(unsigned char operand)
{
	stiva[++varf] = operand;
}
char pop()
{
	return stiva[varf--];
}
int VerificareOperator(unsigned char operand)
{
	if (operand == '*' || operand == '/' || operand == '+' || operand == '-')
		return 1;
	else
		return 0;
}
int Prioritate(unsigned char operand)
{
	if (operand == '+' || operand == '-')
		return 1;
	if (operand == '*' || operand == '/')
		return 2;
	else
		return 0;
}
void Transformare_FP(unsigned char sir[])
{
	int i = 0, j = 0;
	unsigned char operand, afisare_operator;
	stiva[++varf] = '(';
	strcat(sir, ")");
	operand = sir[0];
	while (operand != NULL) {
		if (operand == '(')
			push(operand); 
		else if (operand >= 'a' && operand <= 'z')
			fp[j++] = operand;
		else if (VerificareOperator(operand) == 1) {
			afisare_operator = pop();
			while (Prioritate(afisare_operator) == 2) {
				fp[j++] = afisare_operator;
				afisare_operator = pop();
			}
			push(afisare_operator);
			push(operand);
		}
		else if (operand == ')') {
			afisare_operator = pop();
			while (afisare_operator != '(')
			{
				fp[j++] = afisare_operator;
				afisare_operator = pop();
			}
		}
		operand = sir[++i];
	}
	fp[j] = '\0';
}
int main()
{
	unsigned char sir[50];
	printf("Sirul in forma normala : ");
	gets(sir);
	Transformare_FP(sir);
	printf("Sirul in forma poloneza postfixata : ");
	puts(fp);
	system("pause");
	return 0;
}