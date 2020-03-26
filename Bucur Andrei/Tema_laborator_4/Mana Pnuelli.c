#include <stdlib.h>
#include <stdio.h>
#define MAXIM 100
unsigned st[MAXIM],vf;
unsigned IsStackFull()
{
    if(vf==MAXIM)
    {
        printf("Stiva este plina");
        return 1;
    }
    return 0;
}
unsigned IsStackEmpty()
{
    if(vf==0)
    {
        printf("Stiva este goala");
        return 1;
    }
    return 0;
}
unsigned push(int val)
{
    if(IsStackFull())
        return 0;
    vf++;
    st[vf]=val;
    return 1;
}
unsigned pop()
{
    unsigned aux;
    if(IsStackEmpty())
        return 0;
    aux=st[vf];
    vf--;
    st[vf]=aux-1;
    return 1;
}
void afisare_stiva()
{
    unsigned i;
    printf("Stiva:");
    for(i=1;i<=vf;i++)
        printf("%d ",st[i]);
    printf("\n");
}
int main()
{
    unsigned val;
    printf("Introduceti valoarea argumentului functiei:");
    scanf("%d",&val);
    push(val);
    while(vf!=0)
    {
        if(st[vf]<12)
        {
            push(st[vf]+2);
            afisare_stiva();
        }
        else
        {
            pop();
            afisare_stiva();
        }
    }
    printf("=>f(%d)=%d \n",val,st[vf]);
    return 0;
}
