#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

char stiva[MAX], fpol[MAX];
int varf = 1;
int k = 0;

void pushstack(char x)
{
	stiva[varf] = x;
	varf++;
}

void pushfpol(char x)
{
	fpol[k] = x;
	k++;
}

void popstack()
{
	varf--;
}

int front(char x)
{
	if (x == '+' || x == '-')
		return 2;
	if (x == '/' || x == '*')
		return 1;
	if (x == '(' || x == ')')
		return 0;
	return -1;
}

int main()
{
	char s[MAX];
	int i = 0;
	int l = 0;
	int auxvarf = 0;

	printf("Introduceti datele:");
	scanf("%s", s);

	while (i < strlen(s))
	{
		if (s[i] <= 'z' && s[i] >= 'a')
			pushfpol(s[i]);
		else if (front(s[i]) >= 0)
		{
			pushstack(s[i]);
			if (front(s[i]) == 2)
			{
				popstack();
				auxvarf = varf - 1;
				for (l = auxvarf; l > 0; l--)
				{
					if (stiva[l] != '(')
					{
						if (front(stiva[l]) == 1)
						{
							pushfpol(stiva[l]);
							popstack();
						}
					}
					else break;
				}
				pushstack(s[i]);
			}
			else if (s[i] == ')')
			{
				popstack();
				auxvarf = varf - 1;
				for (l = auxvarf; l > 0; l--)
				{
					if (stiva[l] != '(')
					{
						pushfpol(stiva[l]);
						popstack();
					}
					else
					{
						popstack();
						break;
					}
				}
			}
		}
		i++;
	}
	printf("Forma poloneza: ");
	for (i = 0; i < k; i++)
		printf("%c", fpol[i]);
	printf("\n");
	system("pause");
	return 0;
}
