#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int v[20000], i, poz;
void Generare()
{
    v[0] = 2;
    for (i = 1; i < 20000; i++)
        v[i] = v[i - 1] + 2;
}
void Generare_Inversa()
{
    v[19999] = 2;
    for (i = 19998; i >0; i--)
        v[i] = v[i + 1] + 2;
}
void Cautare_Liniara()
{
    for (i = 0; i <= 20000; i++)
        if (i == poz)
            printf("Numarul de pe pozitia %d fost gasit folosind cautare liniara\n", poz);
}
void Cautare_Binara()
{
    int stg = 0, dr = 19999, i = 0;
    while (stg <= dr)
    {
        i = stg + (dr - 1) / 2;

        if (i == poz)
            printf("Numarul de pe pozitia %d fost gasit folosind cautare binara\n", poz);
        if (i <= poz)
            stg = i + 1;
        else
            dr = i - 1;
    }
}
void Afisare()
{
    for (i = 0; i < 20000; i++)
        printf("%d ", v[i]);
}
int main()
{
    printf("Pozitia:");
    scanf("%d", &poz);
    Generare();
    //Generare_Inversa();
    Cautare_Liniara();
    Cautare_Binara();
    //Afisare();
    return 0;
}