//
//#include<stdio.h>
//#include<stdlib.h>      
//#include<string.h>
//
//#define SIZE 100
//
//char stack[SIZE];
//int top = -1;
//
//
//void push(char item)
//{
//	if (top >= SIZE - 1)
//	{
//		printf("\nStack Overflow.");
//	}
//	else
//	{
//		top = top + 1;
//		stack[top] = item;
//	}
//}
//
//char pop()
//{
//	char item;
//
//		item = stack[top];
//		top = top - 1;
//		return(item);
//}
//
//
//int operator(char simbol)
//{
//	if (simbol == '^' || simbol == '*' || simbol == '/' || simbol == '+' || simbol == '-')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int prioritate(char simbol)
//{
//	if (simbol == '^')
//	{
//		return(3);
//	}
//	else if (simbol == '*' || simbol == '/')
//	{
//		return(2);
//	}
//	else if (simbol == '+' || simbol == '-')       
//	{
//		return(1);
//	}
//	else
//	{
//		return(0);
//	}
//}
//
//void InfixToPostfix(char infix_expr[], char postfix_expr[])
//{
//	int i, j;
//	char item;
//	char x;
//
//	push('(');                               
//	strcat(infix_expr, ")");                  
//
//	i = 0;
//	j = 0;
//	item = infix_expr[i];        
//
//	while (item != '\0')      
//	{
//		if (item == '(')
//		{
//			push(item);
//		}
//		else if (isdigit(item) || isalpha(item))
//		{
//			postfix_expr[j] = item;              
//			j++;
//		}
//		else if (operator(item) == 1)       
//		{
//			x = pop();
//			while (operator(x) == 1 && prioritate(x) >= prioritate(item))
//			{
//				postfix_expr[j] = x;                  
//				j++;
//				x = pop();                      
//			}
//			push(x);
//			
//			push(item);                
//		}
//		else if (item == ')')        
//		{
//			x = pop();                   
//			while (x != '(')                
//			{
//				postfix_expr[j] = x;
//				j++;
//				x = pop();
//			}
//		}
//		i++;
//
//
//		item = infix_expr[i]; 
//	} 
//
//	postfix_expr[j] = '\0'; 
//
//}
//
//int main()
//{
//	char infix[SIZE], postfix[SIZE];        
//
//	printf("\nEnter Infix exprression : ");
//	gets(infix);
//
//	InfixToPostfix(infix, postfix);                  
//	printf("Postfix exprression: ");
//	puts(postfix);                    
//
//	return 0;
//}
