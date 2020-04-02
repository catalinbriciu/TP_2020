#include<stdlib.h>
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
unsigned char IsStackFull(unsigned char *SP)
{
    if((*(SP))==max_lung-1)
       return 1;
       else return 0;
}
unsigned char IsStackEmpty(unsigned char *SP)
{
    if((*(SP))==0)
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
void afisare_stiva(unsigned int Val)
{
    unsigned int aux;
    while(Val)
    {
        aux=Val%10;
        Push(&Stiva[0],&SP,aux);
        Val=Val/10;
    }
    while(IsStackEmpty(&SP)!=1)
    {
        Val=Pop(&Stiva[0],&SP);
        printf("%d\n", Val);
    }
}
int main()
{
    unsigned int Val;
    printf("Dati numarul: ");scanf("%d",&Val);
    printf("Numarul sub forma de stiva este: \n");
    Create(&Stiva[0],&SP);
    afisare_stiva(Val);
    return 0;
}

