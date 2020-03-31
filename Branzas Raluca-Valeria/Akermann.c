#include<stdio.h>
#include<stdlib.h>
int A(int x,int y)
{
    if(x==0&&y!=0)
        return y+1;
    if((x!=0)&&(y==0))
        return A(x-1,1);
    if((x!=0)&&(y!=0))
        return A(x-1,A(x,y-1));
}

int main()
{
    int x,y,Ackermann;
    printf("x=");
    scanf("%d",&x);
    printf("y=");
    scanf("%d",&y);
    Ackermann=A(x,y);
    printf("Rezultatul este: %d",Ackermann);
    return 0;
}
