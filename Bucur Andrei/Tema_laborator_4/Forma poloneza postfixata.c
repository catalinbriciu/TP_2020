#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char st[101],fp[101];
int vf=1,k=0;
void pushst(char x)
{
	st[vf] = x;
	vf++;
}

void pushfp(char x)
{
	fp[k] = x;
	k++;
}

void popst()
{
    vf--;
}

int Prioritate(char x)
{
	if (x=='+'||x=='-')
		return 2;
	if (x=='/'||x=='*')
		return 1;
	if (x=='('||x==')')
		return 0;
	return -1;
}
int main()
{
    char s[101];
    int i=0,auxvf=0,k2=0;
    printf("(E)=");
    scanf("%s",s);
    while(i<strlen(s))
    {
        if(s[i]<='z'&&s[i]>='a')
            pushfp(s[i]);
        else if(Prioritate(s[i])>=0)
        {
            pushst(s[i]);
            if(Prioritate(s[i])==2)
            {
                popst();
                auxvf=vf-1;
                for(k2=auxvf;k2>0;k2--)
                {
                    if(st[k2]!='(')
                    {
                        if(Prioritate(st[k2])==1)
                        {
                            pushfp(st[k2]);
                            popst();
                        }
                    }
                    else break;
                }
                pushst(s[i]);
            }
            else if(s[i]==')')
            {
                popst();
                auxvf=vf-1;
                for(k2=auxvf;k2>0;k2--)
                {
                    if(st[k2]!='(')
                    {
                        pushfp(st[k2]);
                        popst();
                    }
                    else
                    {
                        popst();
                        break;
                    }
                }
           }
       }
       i++;
    }
    printf("Forma poloneza postfixata este: ");
    for(i=0;i<k;i++)
        printf("%c",fp[i]);
    printf("\n");
    return 0;
}
