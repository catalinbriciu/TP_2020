/*Pentru afisarea verticala a unui numar pentru format din mai multe cifre(e.g. 43252) se poate
folosi o stiva in care se vor depune resturile impartirilor la x(x fiind baza de numeratie).Pentru fiecare punct de rezolvat se va genera o noua functie cu prototipul
void Punctul_x(void).
1) Sa se genereze stiva pentru baza 10 pentru nu numar n de 5 cifre citit de la tastatura. (nu e nevoie de afisare)
2) Sa se depuna intr - o noua stiva toate cifrele din stiva de la 1) care sunt divizibile cu 2 folosind operatii pe biti.
3) Sa se extraga si sa se afiseze toate numerele din stiva obtinuta la 2) care au bitul 1 si bitul 2 setat.

Timp de lucru : 40 min*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>


void push(int s[], int vf, int x)
{
    s[++vf] = x;
}
void pop(int vf)
{
    vf--;
}
int top(int s[], int vf)
{
    return s[vf];
}
void Punctul_1(int s[], int vf)
{
    int numar, i;
    scanf("%d", &numar);
    for (i = 1; i <= 5; i++)
    {
        push(s, vf, numar % 10);
        numar = numar / 10;
    }
}

void Punctul_2(int st2[], int vf2, int st1[], int vf1)
{
    int numar, i;
    for (i = 1; i < 5; i++)
    {
        numar = top(st1, vf1);
        pop(vf1);
        if (((numar >> 0) & 1) == 1)
        {
            push(st2, vf2, numar);
        }
    }

}
int main()
{
    int st1[5], vf1 = 0, st2[5], vf2 = 0;
    Punctul_1(st1, vf1);
    Punctul_2(st2, vf2, st1, vf2);


    return 0;
}
