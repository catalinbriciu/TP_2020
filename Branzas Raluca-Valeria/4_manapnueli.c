/*#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define max_lung 100
unsigned char Stiva[max_lung];
unsigned char *SP;
void Create(unsigned char *Stiva, unsigned char *SP)
{

    unsigned char contor;
    *SP=0;
    for (contor =0;contor<max_lung;contor++)
    {
        Stiva[contor]=0;
    }
}
unsigned char IsStackEmpty(unsigned char *SP)
{
    if((*(SP))==0)
       return 1;
       else return 0;
}
unsigned char IsStackFull(unsigned char *SP)
{
    if((*(SP))==max_lung-1)
       return 1;
       else return 0;
}
void Push(unsigned char *Stiva, unsigned char *SP,unsigned char Valoare_noua)
{
    if(IsStackFull(SP)!=1)
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
        *SP=*SP-1;
        ValReturnata=Stiva[*SP];
        return ValReturnata;
    }
    else
        return ValReturnata;
}
unsigned char ManaPnuelli(unsigned char Val)
{
    unsigned char aux;
    Push(&Stiva[0],&SP,Val);
    while(IsStackEmpty(&SP)!=1)
    {
        Val=Pop(&Stiva[0],&SP);
        if(Val<12)
        {
            Push(&Stiva[0],&SP,Val);printf("%d ",Val);
            Push(&Stiva[0],&SP,Val+2);printf("%d ",Val+2);
        }
        else
        {
            if(IsStackEmpty(&SP)!=1)//daca stiva nu e goala
             {
            aux=Val;
            Val=Pop(&Stiva[0],&SP);//penultima valoare
            Val=aux-1;//printf("%d ",Val);
            Push(&Stiva[0],&SP,Val);printf("%d ",Val);
             }
             else //daca stiva e goala
                {Val=Val-1; return Val;}//printf("vall fin %d ",Val);}
        }
        printf("\n");

    }
    //return 0;
}
int main()
{
    unsigned char Val,x;
    printf("Dati valoarea");scanf("%d",&Val);
    Create(&Stiva[0],&SP);
    x=ManaPnuelli;
    printf("Valoarea este %d", x);
    //ManaPnuelli(Val);
   //printf("\nValoarea finala este %d", Val);

    return 0;
}*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define max_lung 100
unsigned char Stiva[max_lung];
unsigned char *SP;
/*int main()
{
    unsigned char Val,x;
    printf("Dati valoarea");scanf("%d",&Val);
    Create(&Stiva[0],&SP);
    x=ManaPnuelli;
    printf("Valoarea este %d", x);

    return 0;
}*/
void Create(unsigned char *Stiva, unsigned char *SP)
{

    unsigned char contor;
    *SP=0;
    for (contor =0;contor<max_lung;contor++)
    {
        Stiva[contor]=0;
    }
}
unsigned char IsStackEmpty(unsigned char *SP)
{
    if((*(SP))==0)
       return 1;
       else return 0;
}
unsigned char IsStackFull(unsigned char *SP)
{
    if((*(SP))==max_lung-1)
       return 1;
       else return 0;
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
        *SP=*SP-1;
        ValReturnata=Stiva[*SP];
        return ValReturnata;
    }
    else
        return ValReturnata;
}
unsigned char ManaPnuelli(unsigned char Val)
{
    unsigned char aux;
    Push(&Stiva[0],&SP,Val);
    while(IsStackEmpty(&SP)!=1)
    {
        Val=Pop(&Stiva[0],&SP);
        if(Val<12)
        {
            Push(Stiva,&SP,Val);
            Push(Stiva,&SP,Val+2);
        }
        else
        {
            if(IsStackEmpty(&SP)!=1)//daca stiva nu e goala
             {
            aux=Val;
            Val=Pop(&Stiva[0],&SP);//penultima valoare
            Val=aux-1;
            Push(&Stiva[0],&SP,Val);
             }
             else //daca stiva e goala
                {Val=Val-1; return Val;}
        }
        printf("\n");

    }
}

int main()
{
    unsigned char Val,x;
    printf("Dati valoarea ");scanf("%d",&Val);
    Create(&Stiva[0],&SP);
    x=ManaPnuelli(Val);
    printf("Valoarea este %d", x);
    return 0;
}
