/*Pentru afisarea verticala a unui numar pentru format din mai multe cifre (e.g. 43252) se poate
folosi o stiva in care se vor depune resturile impartirilor la x (x fiind baza de numeratie). Pentru fiecare punct de rezolvat
se va genera o noua functie cu prototipul
void Punctul_x(void).
1) Sa se genereze stiva pentru baza 8 pentru nu numar n de 5 cifre citit de la tastatura (nu e nevoie de afisare)
2) Sa se depuna intr-o noua stiva toate cifrele din stiva de la 1) care au cel putin 2 biti setati.
3) Sa se extraga si sa se afiseze toate numerele din stiva obtinuta la 2) care au bitul 0 si bitul 2 setat.
*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define max_lung 100
unsigned char *SP,*SP2, Stiva[max_lung],Stiva2[max_lung];
void Creare(unsigned char *Stiva,unsigned char *SP)
{

    unsigned char contor;
    *SP=0;
    for (contor =0; contor<max_lung; contor++)
    {
        Stiva[contor]=0;
    }
}
unsigned char IsStackFull(unsigned char *SP)
{
    if((*(SP))==max_lung-1)
        return 1;
    else
        return 0;
}
unsigned char IsStackEmpty(unsigned char *SP)
{
    if((*(SP))==0)
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
        *SP=*SP-1;
        ValReturnata=Stiva[*SP];
        return ValReturnata;
    }
    else
        return ValReturnata;
}

void Punctul_1(int n)
{
    int rest;
    while(n)
    {
        rest=n%8;
        Push(&Stiva[0],&SP,rest);
        n=n/8;
    }

}
void afisare_stiva(unsigned int Val) //+golire
{
    printf("afisare stiva\n");
    while(IsStackEmpty(&SP2)!=1)
    {
        Val=Pop(&Stiva2[0],&SP2);
        printf("%d\n", Val);
    }
    Val=Pop(&Stiva2[0],&SP2);
    while(IsStackEmpty(&SP2)!=1 && Val==0)
    {
        Val=Pop(&Stiva2[0],&SP2);
    }
    Push(&Stiva2[0],&SP2,Val);
}
void Punctul_2()
{
    long bin = 0;
    int rem, i = 1,j, n,step = 1,nr_biti_1=0;
    for(j=1;j<=5;j++)
    {
    n=Pop(&Stiva[0],*SP);
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
        if(rem==1)
            nr_biti_1++;
    }
    if(nr_biti_1>=2)
    {
        Push(&Stiva2[0],&SP2,n);
    }}
}
void Punctul_3(int n) //interschimbare biti
{
    int j;
    long b2,b5,n2=n, n3 = n;
    for(j=1;j<=5;j++)
    {
    n=Pop(&Stiva2[0],*SP2);
    printf( "\nnr in subprogram: %ld \n ", n2);
    b2 = 0b1 & (n2>>0);
    printf("n: %d bit: %d\n", n2, b2);
    b5 = 0b1 & (n3>>2);
    printf( "\n n:%ld bit: %ld \n", n2, b5);

    if(b2==1 && b5==1)
    printf("%ld ",n);
    }

}
int main()
{
    int n,Val;
    scanf("%d",&n);
    Punctul_1(n);
    //afisare_stiva(Val);
    Punctul_2();
    Punctul_3( n);
    afisare_stiva(Val);
    system("pause");
    return 0;
}
