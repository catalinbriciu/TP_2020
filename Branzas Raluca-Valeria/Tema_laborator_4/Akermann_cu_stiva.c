
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define max 12

typedef struct stivaAkkidk
{
    unsigned char x;
    unsigned char y;
}stivaAkk;
unsigned char *sp;
stivaAkk stiva[max];
void create(stivaAkk *stiva,unsigned char *sp)
{
    unsigned char c;
    *sp=0;
    for(c=0; c<max; c++)
    {
        stiva[c].x=0;
        stiva[c].y=0;
    }
}
unsigned char IsStackEmpty(unsigned char *sp)
{
    if((*(sp))==0)
       return 1;
       else return 0;
}
unsigned char IsStackFull(unsigned char *sp)
{
    if((*(sp))==max-1)
       return 1;
       else return 0;
}
void Push(stivaAkk *stiva, unsigned char *sp,unsigned char Valoare_noua_x, unsigned char Valoare_noua_y)
{
    if(!IsStackFull(sp))
    {
        stiva[*sp].x=Valoare_noua_x;
        stiva[*sp].y=Valoare_noua_y;
        *sp=*sp+1;
    }
    else
    {
        printf("Stiva e plina");
    }
}
stivaAkk Pop(stivaAkk *stiva, unsigned char *sp)
{
    stivaAkk rez;
    rez.x=0;
    rez.y=0;
    if(IsStackEmpty(&sp)!=1)//daca stiva NU e goala
    {
        *sp=*sp-1;
        rez.x=stiva[*sp].x;
        rez.y=stiva[*sp].y;
        return rez;
    }
    else
        return rez;
}
unsigned char Akermann(stivaAkk val)
{
    unsigned char mana_pu=0;
    stivaAkk pop_val1;
    stivaAkk pop_val2;
    Push(&stiva[0], &sp,val.x,val.y);
    while(IsStackEmpty(&sp)!=1)
    {
        pop_val1=Pop(&stiva[0], &sp);
        if(pop_val1.x!=0 && pop_val1.y!=0)
        {
            Push(&stiva[0], &sp,pop_val1.x,pop_val1.y);
            Push(&stiva[0], &sp,pop_val1.x,pop_val1.y-1);
        }

        else
        {
            if(pop_val1.y==0)
            {
                Push(&stiva[0], &sp,pop_val1.x-1,1);
            }
            else
            {
                if(pop_val1.x==0)
                {
                    if(IsStackEmpty(&sp)==1)
                    {
                        return pop_val1.y+1;
                    }
                    else
                    {
                        pop_val2=Pop(&stiva[0], &sp);
                        Push(&stiva[0], &sp,pop_val2.x-1,pop_val1.y+1);//pop_val2.x//0
                    }
                }
            }
        }

    }

}
int main()
{
    unsigned char r;
    stivaAkk val;
    //val.x=2;
    //val.y=1;
    printf("Da valoarea lui x:");
    scanf("%d",&val.x);
    printf("Da valoarea lui y:");
    scanf("%d",&val.y);
    create(&stiva[0],&sp);
    r=Akermann(val);
    printf("valoarea returnata este %d: \n",r);
    system("pause");
    return 0;
}
