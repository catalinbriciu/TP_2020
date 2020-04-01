

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max_lung 50
#define max_lung2 50
unsigned char Stiva[max_lung];
unsigned char Stiva2[max_lung];
unsigned char Val[max_lung];
unsigned char *SP,*SP2,*SP3;
void Create(unsigned char *Stiva, unsigned char *SP)
{

    unsigned char contor;
    *SP=0;
    for (contor =0; contor<max_lung; contor++)
    {
        Stiva[contor]=0;
    }
}
void Create2(unsigned char *Stiva2, unsigned char *SP2)
{

    unsigned char contor;
    *SP2=0;
    for (contor =0; contor<max_lung2; contor++)
    {
        Stiva2[contor]=0;
    }
}

unsigned char IsStackEmpty(unsigned char *SP)
{
    if((*(SP))==0)
        return 1;
    else
        return 0;
}
unsigned char IsStackFull(unsigned char *SP)
{
    if((*(SP))==max_lung-1)
        return 1;
    else
        return 0;
}
void Push(unsigned char *Stiva, unsigned char *SP,unsigned char Valoare_noua)
{
    if(IsStackFull(&SP)!=1)
    {
        Stiva[*SP]=Valoare_noua;
        *SP=*SP+1;
    }
    else
    {
        printf("Stiva e plina");
    }
}
unsigned char Pop(unsigned char *Stiva, unsigned char *SP)
{
    unsigned char ValReturnata=0;
    if(IsStackEmpty!=0)//daca stiva NU e goala
    {
        //ValReturnata=Stiva[*SP];
        //Stiva[*SP] = '\0';
        *SP=*SP-1;
        ValReturnata=Stiva[*SP];
        return ValReturnata;
    }
    else
        return ValReturnata;
}
void FormaPoloneza(unsigned char *Val)
{
    unsigned char aux,i,z;
    Push(&Stiva[0],&SP,Val[0]);
    //printf("prima val din stiva: %c si %c\n",Val[0],Stiva[0]);
    //printf("Numarul de caractere din sirul initial %d\n",strlen(Val));

    while(IsStackEmpty(&SP)==0)
    {

        for(i=1; i<strlen(Val); i++)
        {
            if(Val[i]>='a' && Val[i]<='z')
            {
                int aux = SP2 - '\0';
                Push(&Stiva2[0],&SP2,Val[i]);
               // printf("val nr %d din stiva2:%c\n",SP2,Stiva2[aux]);
            }
            else if(Val[i]=='*' || Val[i]=='/' || Val[i] == '(')
            {
                Push(&Stiva[0],&SP,Val[i]);
                //printf("%s\n", Stiva);
            }
            else if(Val[i]=='+' || Val[i]=='-')
            {
                z = Pop(&Stiva[0], &SP);
                while(1)
                {
                    if(z == '*' || z == '/')
                    {
                        Push(&Stiva2[0],&SP2,z);
                       //printf("%s\n", Stiva);
                        z = Pop(&Stiva[0], &SP);
                    }
                    else{
                        Push(&Stiva[0], &SP, z);
                        break;
                    }
                }
                Push(&Stiva[0],&SP,Val[i]);
               //printf("%s\n", Stiva);
            }
            else if(Val[i]==')')
            {
                 z = Pop(&Stiva[0], &SP);
                while(z != '(')
                {
                    Push(&Stiva2[0],&SP2,z);
                    z = Pop(&Stiva[0], &SP);
                }
                //printf("Test %s", Stiva);
            }


        }
    }
    printf("Forma poloneza postfixata este: %s\n",Stiva2);
}

int main()
{
    unsigned char x,contor;
    printf("Dati valoarea ");
    scanf("%s",Val);
    //printf("Forma normala : %s ",Val);
    Create(&Stiva[0],&SP);
    Create2(&Stiva[0],&SP2);
    //lungimeSir(&Val[0], &SP3);
    FormaPoloneza(Val);
    //printf("Forma poloneza postfixata este: %s",Stiva2);
    return 0;
}
