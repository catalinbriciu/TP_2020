#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int P(int n)
{
    int prod;
    if(n==0)return 1;
    //if(n==1) return 1;
    else
        prod=n*P(n-1);
    return prod;
}
int main()
{
   int n;
   scanf("%d",&n);
   printf("%d",P(n));
   return 0;
}
