#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int Sum(int n)
{
    int suma;
    if(n==0)return 0;
    if(n==1) return 1;
    else
        suma=n+Sum(n-1);
    return suma;
}
int main()
{
   int n;
   scanf("%d",&n);
   printf("%d",Sum(n));
   return 0;
}
