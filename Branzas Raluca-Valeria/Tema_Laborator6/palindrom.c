#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int i,k,contor=0,n,v[10],pal[200],sol=0;
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
    return(k==n);
}

void palindrom(int k)
{
    int aux,aux2,n1,n2=0,r,nr=0,n=4,N=0;
    for(i=1; i<=n; i++)
        {
            aux2=v[i]%10;
            N=N*10+aux2;nr++;}
    n1=N;
    nr=0;
    while(N)
    {
       r=N%10;
       n2=n2*10+r;

       N=N/10;
       nr++;
    }
    if(n1==n2)
        {pal[contor]=n1;
        contor++;
        printf("%d\n",n1);
        }
}
void back()
{
    k=1;
    init(k);
    while(k>0)
    {
        iss=0;
        isv=0;
        if(k<=n)
            do
            {
                iss=succesor(k);///cauta succesor
                if(iss)
                    isv=1;

            }
            while(iss && !isv);
        if(iss) /// e succ si e valid
            if(solution(k))
                palindrom(k);
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
    n=4;
    back();
    return 0;
}

