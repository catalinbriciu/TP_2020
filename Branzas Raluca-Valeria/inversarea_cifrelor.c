#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void Inv(int n)
{
    int nr;
    if(n==0)return 0;
    //if(n==1) return 1;
    else
    {
        //if(n!=0)
        printf("%d",n%10);
        return Inv(n/10);
    }


}
int main()
{
   int n;
   scanf("%d",&n);
   //printf("%d",Inv(n));
   Inv(n);
   return 0;
}
