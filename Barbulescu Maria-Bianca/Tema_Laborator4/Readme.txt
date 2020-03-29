#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

FILE *f, *g;
int i = 0, n = 0, vf = 0;
char st[100], fp[100], e[100], ch, h;

char Push(char val)
{
	st[++vf] = val;
	return val;
}

char Pop()
{
	if (vf > 0)
		return st[vf--];
	else
		return '#';
}

char GetTop()
{
	if (vf > 0)
		return st[vf];
	else
		return '#';
}

int GetPriority(char ch)
{
	switch (ch)
	{
	case '*': 
	case '/': return 1;
	case '+':
	case '-': return 2;
	default: return 0;
	}
}

void NextElement(char ch)
{
	if (('a' <= ch) && (ch <= 'z')) {
		fp[n++] = ch; return;
	}
	Push(ch);
	if (ch == '(') return;
	if (ch == ')')
	{
		Pop();
		while ((h = Pop()) != '(')
		{
			fp[n++] = h;
		}
		return;
	}
}

int main()
{
	f = fopen("intrare.txt", "r");
	g = fopen("Iesire.txt", "w");

	while (!feof(f))
	{
		fscanf(f, "%c", ch);
		if (ch == '\n') {
			for (i = 0; i < n; i++)
				fprintf(g, "%c", fp[i]);
			fprintf(g, "\n");
			n = 0;
			vf = 0;

		}
		else
			NextElement(ch);
	}
	fclose(f);
	fclose(g);
	system("pause");
	return 0;
}
