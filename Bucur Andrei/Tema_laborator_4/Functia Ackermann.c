#include <stdlib.h>
#include <stdio.h>

int Ackermann(int a,int b)
{
    if(a!=0&&b!=0)
        Ackermann(a-1,Ackermann(a,b-1));
    if(a!=0&&b==0)
        Ackermann(a-1,1);
    if(a==0&&b!=0)
        return b+1;
}
int main()
{
    int x,y,F;
    printf("Introduceti x:");
    scanf("%d",&x);
    printf("Introduceti y:");
    scanf("%d",&y);
    F=Ackermann(x,y);
    printf("F(%d,%d)=%d",x,y,F);
    return 0;
}
