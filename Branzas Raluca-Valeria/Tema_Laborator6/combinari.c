#include<stdlib.h>
#include<stdio.h>
int i,k, j,n,m,v[10],sol=0,p,Nr[20][20];
char iss,isv=0;
void init(int k)
{
    v[k]=0;
}
int succesor(int k)
{
    if(v[k]<n)
    {
        v[k]++;
        return 1;
    }
    else
        return 0;
}
int valid(int k)
{
    for(i=1; i<k; i++)
        if(v[i]==v[k])
            return 0;
    return 1;
}
int solution(int k)
{
    return(k==m);
}
int valid2()
{
    int ok;
    sol++;
        for(j=0;j<n;j++)
                for(i=1; i<=m; i++)

    {
        if(v[i]==(j+1))
           {printf("%d, %d: \n",v[i],j+1);
          Nr[j][sol]=1;break;}
        else
            Nr[j][sol]=3;
    }
    //

    for(j=1;j<=n;j++)
    {for(p=1;p<=sol;p++)
    printf("%d ",Nr[j][p]);
        printf("\n");
    }
    if(sol!=1)
    for(p=1;p<=sol;p++)
    {
        ok=1;
        for(j=1;j<=n;j++)

    {
        if(Nr[j][sol]!=Nr[j][p])
                {ok=1;break;} /// cand gaseste un ellem diferit iese si se va verifica alta coloana/solutie
            else
            ok=0;
    }

    if(ok==0)///daca solutia noastra are aceleasi elemente ca si alta solutie
    {
        sol--;///solutia nu e buna, stergem solutia
        printf("\n test\n");
        break;
        return 0;
    }
    }
   if(ok==1)
        return 1;
   /* else
        return 0;*/
}
void print()
{
    printf("%d: ",sol);
    for(i=1; i<=m; i++)
        printf("%d ",v[i]);
    printf("\n");
}
void back()
{
    k=1;
    init(k);
    while(k>0)
    {
        iss=0;
        isv=0;
        if(k<=m) ///combinari de n luate cate m, nu depasim valoarea in stiva
            do
            {
                iss=succesor(k);///cauta succesor
                if(iss)
                    isv=valid(k);

            }
            while(iss && !isv);
        if(iss) /// e succ si e valid
            if(solution(k))
            {
              if(valid2()==1);
               print();}
            else
            {
                k++;
                init(k);
            }
        else
            k--; /// nu e succ, coboara poz in stiva
    }
}
int main()
{
    n=3;
    m=2;
    back();
    return 0;
}

