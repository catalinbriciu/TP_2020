#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int cmmdc(int a, int b)
{
    int prod;
    if(b==0)return a;
    //if(n==1) return 1;
    else
     return cmmdc(b,a%b);
}
int main()
{
   int a,b;
   scanf("%d",&a);
   scanf("%d",&b);
   printf("%d",cmmdc(a,b));
   return 0;
}

