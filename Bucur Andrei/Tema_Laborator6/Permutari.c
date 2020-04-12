#include <stdio.h>
#include <stdlib.h>

int v[50],vf,i=1,n,isS,isV;

void Init(int k)
{
    v[vf]=0;
}

int Succesor(int vf)
{
    if (v[vf]<n)
    {
        v[vf]++;
        return 1;
    }
    else
        return 0;
}

int Valid(int vf)
{
    for (i=1;i<vf;i++)
        if (v[i]==v[vf])
            return 0;
    return 1;
}

int Solution(int vf)
{
    return (vf==n);
}

void Afisare()
{
    for (i=1;i<=n;i++)
        printf("%d ",v[i]);
    printf("\n");
}

void Back(int n)
{
    vf=1;
    Init(vf);
    while (vf>0)
    {
        isS=0;
        isV=0;
        if (vf<=n)
        {
            do
            {
                isS=Succesor(vf);
                if (isS)
                    isV=Valid(vf);
            } while (isS && !isV);
        }
        if (isS)
        {
            if (Solution(vf))
                Afisare();
            else
            {
                vf++;
                Init(vf);
            }
        }
        else
            vf--;
    }
}

int main()
{
    printf("n=");
    scanf("%d", &n);
    printf("\n");
    printf("Permutari de %d:\n\n",n);
    Back(n);

}
