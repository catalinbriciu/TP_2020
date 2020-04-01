#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
char stiva[100];
int varf = -1;
void push(char element)
{
	stiva[++varf] = element;
}
int pop(int stiva[],int varf)
{
	return stiva[varf--];
}
int main()
{
	char expresie[50] = { "(a*(b-c)+d/(e+f*h)-i)" };
	char forma_poloneza[50];
	int i = 1;//indicele pentru expresie//
	int j = 0;//indicele pentru vector//
	push(expresie[0]);
	while (varf != -1)
	{
		if (expresie[i] >= 'a' && expresie[i] <= 'z')//daca e litera//
		{
			forma_poloneza[j] = expresie[i];//se pune litera in vector//
			j++;
		}
		else
			if (expresie[i] == '*' || expresie[i] == '/')//daca are prioritatea 1//
			{
				push(expresie[i]);//se pune operatorul in stiva//
			}
			else
				if (expresie[i] == '+' || expresie[i] == '-')//daca are prioritatea 2//
				{
					while (stiva[varf] == '*' || stiva[varf] == '/')//cat timp varful stivei este un operator cu prioritate 1//
					{
						forma_poloneza[j] =pop( stiva,varf);//se scoate din stiva si se pune in vector//
						j++;
					}
					push(expresie[i]);//se pune in stiva operatorul cu prioritatea 2//
				}
				else
					if (expresie[i] == '(')
					{
						push(expresie[i]);
					}
					else
						if (expresie[i] == ')')
						{
							while (stiva[varf] != '(')//se scot din stiva si se pun in vector pana la '('//
							{
								forma_poloneza[j] = pop( stiva,varf);
								j++;
							}
							varf--; //se elimina paranteza '(' din stiva//

						}
		i++;
	}
	forma_poloneza[j] = NULL;
	printf("%s\n", forma_poloneza);
	system("pause");
	return 0;
}