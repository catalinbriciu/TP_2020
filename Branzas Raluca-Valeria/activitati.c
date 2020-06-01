//planificare activitati
#include<stdlib.h>
#include<stdio.h>
void PlanificareAct(int ti[], int tf[], int n)
{
    int i, j;
    i = 0;
    printf("%d ", i);
    for (j = 1; j < n; j++)
    {
      if (ti[j] >= tf[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}
int main()
{
    int ti[] =  {1, 3, 0, 5, 8, 5};
    int tf[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(ti)/sizeof(ti[0]);
    PlanificareAct(ti, tf, n);
    return 0;
}
