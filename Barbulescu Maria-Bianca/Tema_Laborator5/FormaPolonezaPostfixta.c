

#include<stdio.h>
#include<stdlib.h>      
#include<string.h>

#define SIZE 100;

char st[SIZE];
int top = -1;

void push(char ch)
{
	if (top >= SIZE - 1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top + 1;
		st[top] = ch;
	}
}

char pop()
{
	char ch;

		ch = st[top];
		top = top - 1;
	return(ch);
}


int operator(char op)
{
	if (op == '^' || op == '*' || op == '/' || op== '+' || op == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int prioritate(char op)
{
	if (op == '^')
	{
		return(3);
	}
	else if (op == '*' || op == '/')
	{
		return(2);
	}
	else if (op == '+' || op == '-')       
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void InfixToPostfix(char infix[], char postfix[])
{
int i, j;
	char ch
	char x;
	push('(');                               
	strcat(infix, ")");                  

	i = 0;
	j = 0;
	ch=fix[i];        

	while (ch= '\0')      
	{
		if (ch= '(')
		{
			push(ch);
		}
		else if (isdigit(item) || isalpha(item))
		{
			postfix[j] = ch;
			j++;
		}
	
	else if (operator(ch)==1)       
	{
			x = pop();
			while (operator(x) == 1 && prioritate(x) >= prioritate(ch))
			{
				postfix[j] = x;                  
			j++;
			x = pop();                      
		}
			push(x);
		
			push(ch);
		}
		else if (ch=')')
		{
			x = pop();                   
			while (x != '(')                
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		i++;


		ch = infix[i];
	} 

	postfix[j] = '\0'; 
}

int main()
{
	char infix[SIZE], postfix[SIZE];        

	printf("\n (E)= ");
    gets(infix);
	InfixToPostfix(infix, postfix);                  
	printf("Forma postfixata: ");
	puts(postfix);                    
	system("pause");
	return 0;
}