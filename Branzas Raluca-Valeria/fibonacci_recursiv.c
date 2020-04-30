#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int F(int n)
{
    if(n==0) return 0;
    else
        if(n==1) return 1;
    else
        return F(n-2)+F(n-1);
}
int main()
{
   int n;
   scanf("%d",&n);
   printf("%d",F(n));
   return 0;
}
