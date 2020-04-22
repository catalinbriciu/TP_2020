#include<stdlib.h>
#include<stdio.h>
int i,k, j,n,m,v[10],sol=0;
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
void print()
{
    printf("%d: ",++sol);
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
                print();
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
    m=2;
    back();
    return 0;
}

