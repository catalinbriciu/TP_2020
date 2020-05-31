#include <stdio.h>

int n = 7, x[10], G = 15;
int greutate[10] = { 7, 13, 2, 1, 4, 6, 9 };
int cost[10] = { 4, 6, 5, 9, 10, 3, 16 };

void Umplere()
{
    int G_curenta, i, imax;

    G_curenta = G;
    while (G_curenta > 0)
    {

        imax = -1;
        for (i = 0; i < n; ++i)
            if ((x[i] == 0) && ((imax == -1) || ((float)cost[i] / greutate[i] > (float)cost[imax] / greutate[imax])))
                imax = i;
        x[imax] = 1;
        G_curenta -= greutate[imax];
        if (G_curenta >= 0)
            printf("Obiectul %d (cost: %d, %dKg)\n", imax + 1, cost[imax], greutate[imax]);
        else {
            printf("Obiectul %d (cost: %d, %dKg). S-a adaugat %d%% din acest obiect\n", imax + 1, cost[imax], greutate[imax], (int)((1 + (float)G_curenta / greutate[imax]) * 100));

        }
    }

}

int main()
{
    Umplere();

    system("pause");
    return 0;
}