#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stiva[100];
int vf = -1;
void push(char elem)
{
	stiva[++vf] = elem;
}
void pop(void)
{
	return stiva[vf--];
}
int main()
{
	char exp[23] = { "(a*(b-c)+d/(e+f*h)-i)" };
	char fp[23];
	int i = 1;//indicele pentru expresie
	int j = 0;//indicele pentru vector
	push(exp[0]);
	while (vf != -1)
	{
		if (exp[i] >= 'a' && exp[i] <= 'z')//daca e litera
		{
			fp[j] = exp[i];//se pune litera in vector
			j++;
		}
		else
			if (exp[i] == '*' || exp[i] == '/')//daca are prioritatea 1
			{
				push(exp[i]);//se pune operatorul in stiva
			}
			else
				if (exp[i] == '+' || exp[i] == '-')//daca are prioritatea 2
				{
					while (stiva[vf] == '*' || stiva[vf] == '/')//cat timp varful stivei este un operator cu prioritate 1
					{
						fp[j] = pop();//se scoate din stiva si se pune in vector
							j++;
					}
					push(exp[i]);//se pune in stiva operatorul cu prioritatea 2
				}
				else
					if (exp[i] == '(')
					{
						push(exp[i]);
					}
					else
						if (exp[i] == ')')
						{
							while (stiva[vf] != '(')//se scot din stiva si se pun in vector pana la '('
							{
								fp[j] = pop();
								j++;
							}
							vf--; //se elimina paranteza '(' din stiva

						}
		i++;
	}
	fp[j] = NULL;
	prinf("%s\n", fp);
	system("pause");
	return 0;
}