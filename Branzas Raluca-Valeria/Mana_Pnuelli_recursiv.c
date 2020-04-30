#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int MP(int n)
{
    if(n>=12)
        return n-1;
    else
    {
        return MP(MP(n+2));
    }
}
int main()
{
   int n;
   scanf("%d",&n);
   printf("%d",MP(n));
   return 0;
}
